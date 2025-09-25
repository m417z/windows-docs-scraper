# DXGKCB_ALLOCATEPAGESFORMDL callback function

## Description

**DXGKCB_ALLOCATEPAGESFORMDL** allocates physical memory pages for a memory descriptor list (MDL) to be mapped to the IOMMU's logical address space.

## Parameters

### `hAdapter` [in]

A handle to the display adapter.

### `pAllocatePagesForMdl` [in/out]

Pointer to a [**DXGKARGCB_ALLOCATEPAGESFORMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_allocatepagesformdl) structure that contains arguments to allocate pages for MDL.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS error code.

## Remarks

This callback function is a Windows graphics port driver function equivalent to the [**MmAllocatePagesForMdl** function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdl).

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_ALLOCATEPAGESFORMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_allocatepagesformdl) and then call **DxgkCbAllocatePagesForMdl** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

All memory accessed by the GPU during paging operations, or mapped via the GpuMmu must be mapped to the IOMMU. *Dxgkrnl* provides callbacks to the kernel-mode driver to allow the allocation and remapping in one step.

> [!NOTE]
> Calls to **DXGKCB_ALLOCATEPAGESFORMDL** are limited to the 4GB PAGE_SIZE MDL restriction, and *Dxgkrnl* always specifies the **MM_ALLOCATE_FULLY_REQUIRED** flag in the internal call to [**MmAllocatePagesForMdlEx** function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdl). The driver should also not lock any memory. *Dxgkrnl* will manage locked pages for the driver, and once the memory is remapped, the logical address of the pages provided to the driver may no longer match the physical addresses.

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKARGCB_ALLOCATEPAGESFORMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_allocatepagesformdl)

[**DXGKCB_FREEPAGESFROMMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_freepagesfrommdl)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)