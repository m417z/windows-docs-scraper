# KeQueryDpcWatchdogInformation function

## Description

The **KeQueryDpcWatchdogInformation** routine returns the deferred procedure call (DPC) watchdog timer values for the current processor.

## Parameters

### `WatchdogInformation` [out]

A pointer to a caller-supplied [KDPC_WATCHDOG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kdpc_watchdog_information) structure. The routine writes the current DPC watchdog timer values to this structure.

## Return value

**KeQueryDpcWatchdogInformation** returns an NTSTATUS value. Possible return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | **KeQueryDpcWatchdogInformation** was called while a DPC was running on the current processor. |
| **STATUS_UNSUCCESSFUL** | The current processor was not running a DPC when **KeQueryDpcWatchdogInformation** was called. |

## Remarks

The **KeQueryDpcWatchdogInformation** routine can be called from a DPC routine or at an IRQL= DISPATCH_LEVEL to determine the amount of time that remains before a DPC time-out occurs. The operating system implements a DPC watchdog timer to detect when a single DPC routine runs for too long, or when a series of queued DPC routines runs back-to-back for too long. If DPC time-out errors are enabled, and if either a DPC routine exceeds the time limit for a single routine, or a series of DPC routines exceeds the aggregate time limit, a [DPC_WATCHDOG_VIOLATION](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x133-dpc-watchdog-violation) (0x133) bug check occurs.

**KeQueryDpcWatchdogInformation** must be called while a DPC is running or invoked at an IRQL= DISPATCH_LEVEL or higher on the current processor. Otherwise, the call fails and returns STATUS_UNSUCCESSFUL.

DPC routines should run only for brief periods, and should delegate as much processing as possible to worker threads. To avoid degrading system responsiveness, a typical DPC routine should run for no more than 100 microseconds each time it is called. For more information, see [Guidelines for Writing DPC Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/guidelines-for-writing-dpc-routines).

## See also

[KDPC_WATCHDOG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kdpc_watchdog_information)