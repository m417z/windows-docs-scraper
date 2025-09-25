# DXGKCB_UPDATECONTEXTALLOCATION callback function

## Description

**DXGKCB_UPDATECONTEXTALLOCATION** updates the content of a context allocation.

## Parameters

### `hAdapter` [in]

A handle to the display adapter.

### `pArgs` [in]

The [**DXGKARGCB_UPDATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_updatecontextallocation) structure that describes the operation.

## Return value

**DXGKCB_UPDATECONTEXTALLOCATION** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_UPDATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_updatecontextallocation) and then call **DxgkCbUpdateContextAllocation** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

The video memory manager maps the specified allocation in the paging process address space, then calls **DXGKCB_UPDATECONTEXTALLOCATION** to trigger a context allocation update paging operation, passing the kernel-mode display driver the specified driver private data.

The call to **DXGKCB_UPDATECONTEXTALLOCATION** returns when the update to the context allocation is completed.

## See also

[**DXGKARGCB_UPDATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_updatecontextallocation)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)