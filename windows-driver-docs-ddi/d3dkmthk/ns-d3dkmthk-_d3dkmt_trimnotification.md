# _D3DKMT_TRIMNOTIFICATION structure

## Description

**D3DKMT_TRIMNOTIFICATION** is used to notify a driver to trim its memory residency list.

## Members

### `Context` [in]

The caller-supplied context for the callback notification.

### `Flags` [in]

A [D3DDDI_TRIMRESIDENCYSET_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_trimresidencyset_flags) structure containing the trimming behavior flags.

### `NumBytesToTrim` [in]

When **TrimToBudget** is set, this value specifies how much the application should evict in order to meet its current memory budget.

## See also

[D3DDDI_TRIMRESIDENCYSET_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_trimresidencyset_flags)