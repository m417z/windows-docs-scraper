# DXGKCB_DESTROYCONTEXTALLOCATION callback function

## Description

**DXGKCB_DESTROYCONTEXTALLOCATION** frees a resource that was previously allocated for a GPU or device-specific context.

## Parameters

### `hAdapter` [in]

Handle to the graphics adapter for which the allocation was created. The display miniport driver receives the handle from the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure in a call to its [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `hAllocation` [in]

Handle that was assigned by the DirectX graphics subsystem (*Dxgkrnl*) to the context allocation. The display miniport driver receives the handle from the **hAllocation** member of the [**DXGKARGCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_createcontextallocation) structure in a call to the [**DXGKCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation) function.

## Return value

**DXGKCB_DESTROYCONTEXTALLOCATION** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The display miniport driver calls [**DXGKCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation) to allocate a context resource. After such a call, the driver can call **DXGKCB_DESTROYCONTEXTALLOCATION** at any time to free the resource.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, call **DxgkCbDestroyContextAllocation** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_createcontextallocation)

[**DXGKCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)