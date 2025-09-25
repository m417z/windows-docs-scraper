# DXGKDDI_SETROOTPAGETABLE callback function

## Description

**DxgkDdiSetRootPageTable** sets the root page table for the given context. This function is used to notify a context when its associated root page table is resized or moved in memory.

This is level 1 synchronization function. The targeted context is guaranteed to be idled (i.e. not scheduled) while its root page table is being updated.

## Parameters

### `hAdapter`

A handle to the display adapter.

### `pSetPageTable`

The [DXGKARG_SETROOTPAGETABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setrootpagetable) structure that describes the operation.

## See also

[DXGKARG_SETROOTPAGETABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setrootpagetable)