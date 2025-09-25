# _DXGK_BUILDPAGINGBUFFER_COPYPAGETABLEENTRIES structure

## Description

**DXGK_BUILDPAGINGBUFFER_COPYPAGETABLEENTRIES** describes the operation used copy page table entries from one location to another.

## Members

### `NumRanges`

The number of elements in the **pRanges** array.

### `pRanges`

A pointer to a [DXGK_BUILDPAGINGBUFFER_COPY_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_copy_range) structure describing each range of page table entries to copy.

## See also

[DXGKARG_BUILDPAGINGBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer)

[DXGK_BUILDPAGINGBUFFER_COPY_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_copy_range)