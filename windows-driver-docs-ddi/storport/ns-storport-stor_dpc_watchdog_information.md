## Description

**STOR_DPC_WATCHDOG_INFORMATION** holds time-out information about the current deferred procedure call (DPC).

## Members

### `DpcTimeLimit`

Time limit (in ticks) for a single, current deferred procedure call. If DPC time-out has been disabled, this value is set to 0.

### `DpcTimeCount`

Time remaining (in ticks) for the current deferred procedure call, if DPC time-out has been enabled.

### `DpcWatchdogLimit`

Total time limit permitted for a sequence of deferred procedure calls. If DPC watchdog has been disabled, this value is set to zero.

### `DpcWatchdogCount`

Time value remaining (in ticks) for the current sequence of deferred procedure calls, if enabled.

### `Reserved`

Reserved for system use.

## See also

[**StorPortQueryDpcWatchdogInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_dpc_watchdog_information)