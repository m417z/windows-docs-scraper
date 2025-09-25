# DXGKCB_ALLOCATECONTIGUOUSMEMORY callback function

## Description

**DXGKCB_ALLOCATECONTIGUOUSMEMORY** allocates contiguous memory regions in the IOMMU's logical address space.

## Parameters

### `hAdapter` [in]

Handle to a display adapter.

### `pAllocateContiguousMemory` [in/out]

Pointer to a [**DXGKARGCB_ALLOCATECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_allocatecontiguousmemory) structure that contains arguments to allocate contiguous memory.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS error code.

## Remarks

 This callback function is *Dxgkrnl*'s equivalent to the [**MmAllocateContiguousMemory** function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemory).

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_ALLOCATECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_allocatecontiguousmemory) and then call **DxgkCbAllocateContiguousMemory** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

All memory accessed by the GPU during paging operations, or mapped via the GpuMmu must be mapped to the IOMMU. The *Dxgkrnl* provides callbacks to the KMD to allow the allocation and remapping in one step.

> [!NOTE]
> The driver should not lock any memory. *Dxgkrnl* will manage locked pages for the driver, and once the memory is remapped, the logical address of the pages provided to the driver may no longer match the physical addresses.

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKARGCB_ALLOCATECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_allocatecontiguousmemory)

[**DXGKCB_FREECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_freecontiguousmemory)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)