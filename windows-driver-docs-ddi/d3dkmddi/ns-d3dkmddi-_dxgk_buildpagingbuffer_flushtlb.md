# _DXGK_BUILDPAGINGBUFFER_FLUSHTLB structure

## Description

**DXGK_BUILDPAGINGBUFFER_FLUSHTLB** is used as part of a flush translation look-aside buffer (TLB) operation.

## Members

### `RootPageTableAddress`

Physical address of the root page table being invalidated.

### `hProcess`

KMD process handle, returned from [DxgkDdiCreateProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess), that the page table belongs to.

### `StartVirtualAddress`

The start of the affected GPU virtual address range.

### `EndVirtualAddress`

The end of the affected GPU virtual address range. When both **StartVirtualAddress** and **EndVirtualAddress** are zero, the entire GPU virtual address range is affected.