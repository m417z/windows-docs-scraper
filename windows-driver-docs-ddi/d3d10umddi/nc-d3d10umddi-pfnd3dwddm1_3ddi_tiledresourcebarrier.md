# PFND3DWDDM1_3DDI_TILEDRESOURCEBARRIER callback function

## Description

Specifies a data access ordering constraint between multiple tiled resources. For more info about this constraint, see Remarks.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `TiledResourceAccessBeforeBarrierHandleType`

A handle to the tiled resource.

### `hTiledResourceAccessBeforeBarrier`

A handle to a resource that was created with the **D3DWDDM1_3DDI_RESOURCE_MISC_TILED** flag. Access operations on this object must complete before the access operations on the object that *hTiledResourceAccessAfterBarrier* specifies.

### `TiledResourceAccessAfterBarrierHandleType`

The [D3D11DDI_HANDLETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_handletype) handle type of the resources pointed to by the *hTiledResourceAccessBeforeBarrier* and *hTiledResourceAccessAfterBarrier* parameters.

### `hTiledResourceAccessAfterBarrier`

A handle to a resource that was created with the **D3DWDDM1_3DDI_RESOURCE_MISC_TILED** flag. Access operations on this object must begin after the access operations on the object that *hTiledResourceAccessBeforeBarrier* specifies.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The Direct3D runtime performs minimal validation of parameters.

Apps can use tiled resources to reuse tiles in different resources. But a device and driver might not be able to determine whether some memory in a tile pool that was just rendered to is now being used for reading.

The Direct3D runtime calls *TiledResourceBarrier* to inform the driver that operations issued to the resource before the call must complete before any accesses that occur after the call using a different tiled resource that shares the same memory.

Either or both of the *hTiledResourceAccessBeforeBarrier* and *hTiledResourceAccessAfterBarrier* parameters (before or after the barrier) can be **NULL**. **NULL** before the barrier means that all tiled resource accesses before the barrier must complete before the resource specified after the barrier can be referenced by the GPU. **NULL** after the barrier means that any tiled resources accessed after the barrier can only be executed by the GPU after accesses to the tiled resources before the barrier are finished. If both are **NULL**, all previous tiled resource accesses must be complete before any subsequent tiled resource access can proceed.

If no calls are made to *TiledResourceBarrier*,
the driver can assume that accesses to different tiled resources
do not conflict with each other.

## See also

[D3D11DDI_HANDLETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_handletype)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)