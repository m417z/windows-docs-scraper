# _DXGK_QUERYPAGETABLELEVELDESCIN structure

## Description

The **DXGK_QUERYPAGETABLELEVELDESCIN** structure is used to request page level descriptors from the [Dxgkrnl Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## Members

### `LevelIndex`

A zero-based physical adapter index (engine ordinal) for which the data is queried.

### `PhysicalAdapterIndex`

A zero-based page table level index for the information requested.

## Remarks

To get page table level descriptors Dxgkrnl calls [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) with the following parameters:

```
DXGKARG_QUERYADAPTERINFO::Type = DXGKQAITYPE_PAGETABLELEVELDESC;
DXGKARG_QUERYADAPTERINFO::pInputData = DXGK_QUERYPAGETABLELEVELDESCIN
DXGKARG_QUERYADAPTERINFO::InputDataSize = sizeof(QUERYPAGETABLELEVELDESCIN)
DXGKARG_QUERYADAPTERINFO::pOutputData = pointer to DXGK_PAGE_TABLE_LEVEL_DESC
DXGKARG_QUERYADAPTERINFO::OutputDataSize = sizeof(DXGK_PAGE_TABLE_LEVEL_DESC);
```