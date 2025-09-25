# _DXGK_BUILDPAGINGBUFFER_COPY_RANGE structure

## Description

**DXGK_BUILDPAGINGBUFFER_COPY_RANGE** is used as part of a page table entry copy operation.

## Members

### `NumPageTableEntries`

The number of page table entries to copy.

### `SrcPageTableAddress`

The virtual address of the source page table for the range. The address is aligned to 64KB boundary.

### `DstPageTableAddress`

The virtual address of the destination page table for the range. The address is aligned to 64KB boundary.

### `SrcStartPteIndex`

The index of the first page table entry in the source page table for the range.

### `DstStartPteIndex`

The index of the first page table entry in the destination page table for the range.

## See also

[DXGKARG_BUILDPAGINGBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer)

[DXGK_BUILDPAGINGBUFFER_COPYPAGETABLEENTRIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_copypagetableentries)