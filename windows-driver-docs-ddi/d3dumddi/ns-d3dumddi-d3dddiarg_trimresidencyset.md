# D3DDDIARG_TRIMRESIDENCYSET structure

## Description

**D3DDDIARG_TRIMRESIDENCYSET** is used with [pfnTrimResidencySet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_trimresidencyset) by a user mode driver to trim the residency list for a given device.

## Members

### `TrimFlags`

The trimming behavior flags.

### `NumBytesToTrim`

When **TrimToBudget** is set, this value specifies how much the application should evict in order to meet its current memory budget.

## See also

[pfnTrimResidencySet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_trimresidencyset)