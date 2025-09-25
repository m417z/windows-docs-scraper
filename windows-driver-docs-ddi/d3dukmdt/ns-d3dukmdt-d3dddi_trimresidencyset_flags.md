# D3DDDI_TRIMRESIDENCYSET_FLAGS structure

## Description

**D3DDDI_TRIMRESIDENCYSET_FLAGS** is used with [pfnTrimResidencySet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_trimresidencyset) to trim the residency list for a given device.

## Members

### `PeriodicTrim`

When **PeriodicTrim** flag is set, the driver is required to performed the following operations:

* Trim all allocations that were not referenced since the previous periodic trim request
  by comparing the allocation last referenced fence with the last periodic trim context fence.
* Refresh the last periodic trim context fence with the last completed context fence.

### `RestartPeriodicTrim`

May not be set together with **PeriodicTrim** flag.
Reset the last periodic trim context fence to the last completed context fence.

### `TrimToBudget`

Indicates that the application usage is over the memory budget
and that **NumBytesToTrim** bytes should be trimmed to fit in the new memory budget.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

The consolidated value of the bit-fields in the structure.

## See also

[pfnTrimResidencySet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_trimresidencyset)