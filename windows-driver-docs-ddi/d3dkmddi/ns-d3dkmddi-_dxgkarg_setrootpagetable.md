# _DXGKARG_SETROOTPAGETABLE structure

## Description

**DXGKARG_SETROOTPAGETABLE** is used by the [DxgkDdiSetRootPageTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setrootpagetable)device driver interface (DDI) to notify a context when its associated root page table is resized or moved in memory.

## Members

### `hContext`

A context handle returned by [DxgkDdiCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext).

### `Address`

The GPU physical address of the root page table.

### `NumEntries`

 The root page table size in entries. GPU should generate invalid fault when a virtual address has a top level page table entry index, which is greater or equal this value.

## See also

[DxgkDdiCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext)

[DxgkDdiSetRootPageTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setrootpagetable)