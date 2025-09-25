# _KDPC_WATCHDOG_INFORMATION structure

## Description

The **KDPC_WATCHDOG_INFORMATION** structure holds time-out information about the current deferred procedure call (DPC).

## Members

### `DpcTimeLimit`

Time limit for a single, current deferred procedure call. If DPC time-out has been disabled, this value is set to 0.

### `DpcTimeCount`

Time remaining for the current deferred procedure call, if DPC time-out has been enabled.

### `DpcWatchdogLimit`

Total time limit permitted for a sequence of deferred procedure calls. If DPC watchdog has been disabled, this value is set to zero.

### `DpcWatchdogCount`

Time value remaining for the current sequence of deferred procedure calls, if enabled.

### `Reserved`

Reserved for system use.

## Remarks

Time figures stored in each member are dimensionless.

## See also

[KeQueryDpcWatchdogInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerydpcwatchdoginformation)