# DXGKDDI_DESTROYALLOCATION callback function

## Description

The *DxgkDdiDestroyAllocation* function releases allocations.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pDestroyAllocation` [in]

A pointer to a [DXGKARG_DESTROYALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_destroyallocation) structure that contains information for releasing allocations.

## Return value

*DxgkDdiDestroyAllocation* returns STATUS_SUCCESS, or an appropriate error result if the allocations are not successfully released.

## Remarks

When the user-mode display driver calls the [pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb) function, the DirectX graphics kernel subsystem (which is part of *Dxgkrnl.sys*) calls the display miniport driver's *DxgkDdiDestroyAllocation* function to release the allocations. The display miniport driver should clean up its internal data structures and references to the allocations. The Microsoft Direct3D runtime initiates calls to the video memory manager (which is also part of *Dxgkrnl.sys*), which then calls the GPU scheduler (which is also part of *Dxgkrnl.sys*) to synchronize before video memory is actually released.

The display miniport driver can release the entire resource as well as allocations. To determine whether the resource should be released, the display miniport driver can check whether the **DestroyResource** flag is set in the **Flags** member of the [DXGKARG_DESTROYALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_destroyallocation) structure that the *pDestroyAllocation* parameter points to. To release the resource, the display miniport driver must clean up the handle that the **hResource** member of DXGKARG_DESTROYALLOCATION specifies. If the display miniport driver does not release the resource, the driver can change the value in **hResource** if necessary.

*DxgkDdiDestroyAllocation* should be made pageable.

## See also

[DXGKARG_DESTROYALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_destroyallocation)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb)