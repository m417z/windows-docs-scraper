## Description

**StorPortQueryDpcWatchdogInformation** queries DPC watchdog timer values for the current processor.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the miniport's device extension.

### `DpcWatchdogInformation` [out]

Pointer to a [**STOR_DPC_WATCHDOG_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_dpc_watchdog_information) structure in which the DPC watchdog information will be written.

## Return value

This function returns one of the following status codes.

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The DPC watchdog information was successfully queried. |
| STOR_STATUS_INVALID_PARAMETER | A parameter is invalid; for example, **DpcWatchdogInformation** is NULL. |
| STOR_STATUS_UNSUCCESSFUL | Returned for other internal system reasons. |

## Remarks

A miniport can call **StorPortQueryDpcWatchdogInformation** at IRQL=DISPATCH_LEVEL to determine the amount of time that remains before a deferred procedure call (DPC) time-out occurs. The operating system implements a DPC watchdog timer to detect when a single DPC routine runs for too long, or when a series of queued DPC routines runs back-to-back for too long. If DPC time-out errors are enabled, and if either a DPC routine exceeds the time limit for a single routine, or a series of DPC routines exceeds the aggregate time limit, a [DPC_WATCHDOG_VIOLATION (0x133)](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x133-dpc-watchdog-violation) bug check occurs.

**StorPortQueryDpcWatchdogInformation** must be called while a DPC is running or invoked at IRQL= DISPATCH_LEVEL or higher on the current processor. Otherwise, the call fails and returns STOR_STATUS_UNSUCCESSFUL.

DPC routines should run only for brief periods, and should delegate as much processing as possible to worker threads. To avoid degrading system responsiveness, a typical DPC routine should run for no more than 100 microseconds each time it is called. For general information, see [Guidelines for Writing DPC Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/guidelines-for-writing-dpc-routines).

## See also

[**STOR_DPC_WATCHDOG_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_dpc_watchdog_information)