# _DXGKARG_SETTRACKEDWORKLOADPOWERLEVEL structure

## Description

Contains information about the power level of a context.

## Members

### `PowerLevel`

The power level is an UINT that varies from 0 to 100, where 100 means the maximum power the engine supports.

### `EffectivePowerLevel`

Returns the effective power level that was set on the context by the driver.

### `Flags`

A combination of [DXGK_TRACKEDWORKLOAD_STATE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_trackedworkload_state_flags).

## Remarks

## See also