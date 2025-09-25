# _DXGK_BUILDPAGINGBUFFER_FILLVIRTUAL structure

## Description

**DXGK_BUILDPAGINGBUFFER_FILLVIRTUAL** is used as part of an operation to fill an allocation with a pattern.

## Members

### `hAllocation`

The kernel mode driver handle of the allocation being filled. The handle is returned from [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation). The allocation properties are needed in order to detect if the allocation is swizzled.

### `AllocationOffsetInBytes`

The offset, in bytes, from the start of the allocation being filled.

### `FillSizeInBytes`

The number of bytes to fill.

### `FillPattern`

The byte pattern to fill with.

### `DestinationVirtualAddress`

The virtual address of the destination in the context of the paging process.

## See also

[DXGKARG_BUILDPAGINGBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)