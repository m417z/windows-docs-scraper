# _DXGKARG_MAPCPUHOSTAPERTURE structure

## Description

The **DXGKARG_MAPCPUHOSTAPERTURE** structure is used to map an allocation, resident in a local memory segment, into the CPU host aperture in order to make it visible to the CPU.

## Members

### `hAllocation`

Specifies the allocation handle, associated with the allocation being mapped. This is the handle, returned by the kernel mode driver from [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) or passed in [DxgkCbCreateContextAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation). This parameter will be **NULL** for implicit allocations, such as a page table.

### `SegmentId`

Specifies the segment identifier of the segment being accessed.

### `PhysicalAdapterIndex`

A zero-based physical adapter index in a linked display adapter link.
The page size is equal to the segment page size, reported in [DXGK_SEGMENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentflags).

**Note** The allocation itself might be aligned on 4KB page boundary. When the segment page size is 64 KB, CPU host aperture in this case will map more than the allocation size.

### `NumberOfPages`

Specifies the number of pages being mapped.

### `pCpuHostAperturePages`

Array of CPU Host Aperture pages to map. This is an array of page indices from the start of the CPU host aperture physical address.

### `pMemorySegmentPages`

MDL-style array of page indices to the allocation pages that need to be mapped into the CPU host aperture. The page indexes starting from 0.