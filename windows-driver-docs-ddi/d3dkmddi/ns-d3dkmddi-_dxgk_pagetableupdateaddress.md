# _DXGK_PAGETABLEUPDATEADDRESS structure

## Description

**DXGK_PAGETABLEUPDATEADDRESS** contains the address of a page table to update. The member containing the address is defined as part of a [DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) operation in the [DXGK_BUILDPAGINGBUFFER_UPDATEPAGETABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_updatepagetable) structure.

## Members

### `CpuVirtual`

The CPU virtual address of the page table to update.

### `GpuPhysical`

The GPU physical address of the page table to update.

### `GpuVirtual`

The GPU virtual address of the page table to update.

## See also

[DXGK_BUILDPAGINGBUFFER_UPDATEPAGETABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_buildpagingbuffer_updatepagetable)

[DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer)