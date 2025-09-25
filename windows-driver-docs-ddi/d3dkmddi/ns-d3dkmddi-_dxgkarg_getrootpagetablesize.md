# _DXGKARG_GETROOTPAGETABLESIZE structure

## Description

**DXGKARG_GETROOTPAGETABLESIZE** is used with [DxgkDdiGetRootPageTableSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getrootpagetablesize).

## Members

### `NumberOfPte` [in]

A pointer to the number of page table entries which are required to be in the root page table.

[out] The actual number of page table entries in the page table with the returned size.

### `PhysicalAdapterIndex`

Physical adapter index (zero for non-linked display adapter configurations).

## See also

[DxgkDdiGetRootPageTableSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getrootpagetablesize)