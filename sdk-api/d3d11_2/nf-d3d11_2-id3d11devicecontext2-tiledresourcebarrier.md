# ID3D11DeviceContext2::TiledResourceBarrier

## Description

Specifies a data access ordering constraint between multiple tiled resources. For more info about this constraint, see Remarks.

## Parameters

### `pTiledResourceOrViewAccessBeforeBarrier` [in, optional]

Type: **[ID3D11DeviceChild](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicechild)***

A pointer to an [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) or [ID3D11View](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11view) for a resource that was created with the [D3D11_RESOURCE_MISC_TILED](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag. Access operations on this object must complete before the access operations on the object that *pTiledResourceOrViewAccessAfterBarrier* specifies.

### `pTiledResourceOrViewAccessAfterBarrier` [in, optional]

Type: **[ID3D11DeviceChild](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicechild)***

A pointer to an [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) or [ID3D11View](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11view) for a resource that was created with the [D3D11_RESOURCE_MISC_TILED](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag. Access operations on this object must begin after the access operations on the object that *pTiledResourceOrViewAccessBeforeBarrier* specifies.

## Remarks

Apps can use tiled resources to reuse tiles in different resources. But, a device and driver might not be able to determine whether some memory in a tile pool that was just rendered to is now being used for reading.

For example, an app can render to some tiles in a tile pool with one tiled resource but then read from the same tiles by using a different tiled resource. These tiled-resource operations are different from using one resource and then just switching from writing with [ID3D11RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rendertargetview) to reading with [ID3D11ShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11shaderresourceview). The runtime already tracks and handles these one resource operations using **ID3D11RenderTargetView** and **ID3D11ShaderResourceView**.

When an app transitions from accessing (reading or writing) some location in a tile pool with one resource to accessing the same memory (read or write) via another tiled resource (with mappings to the same memory), the app must call **TiledResourceBarrier** after the first use of the resource and before the second. The parameters are the *pTiledResourceOrViewAccessBeforeBarrier* for accesses before the barrier (via rendering, copying), and the *pTiledResourceOrViewAccessAfterBarrier* for accesses after the barrier by using the same tile pool memory. If the resources are identical, the app doesn't need to call **TiledResourceBarrier** because this kind of hazard is already tracked and handled.

The barrier call informs the driver that operations issued to the resource before the call must complete before any accesses that occur after the call via a different tiled resource that shares the same memory.

Either or both of the parameters (before or after the barrier) can be **NULL**. **NULL** before the barrier means all tiled resource accesses before the barrier must complete before the resource specified after the barrier can be referenced by the graphics processing unit (GPU). **NULL** after the barrier means that any tiled resources accessed after the barrier can only be executed by the GPU after accesses to the tiled resources before the barrier are finished. Both **NULL** means all previous tiled resource accesses are complete before any subsequent tiled resource access can proceed.

An app can pass a view pointer, a resource, or **NULL** for each parameter. Views are allowed not only for convenience but also to allow the app to scope the barrier effect to a relevant portion of a resource.

For more info about tiled resources, see [Tiled resources](https://learn.microsoft.com/windows/desktop/direct3d11/tiled-resources).

## See also

[ID3D11DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11devicecontext2)