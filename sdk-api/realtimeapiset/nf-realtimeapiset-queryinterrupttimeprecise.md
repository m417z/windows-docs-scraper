# QueryInterruptTimePrecise function

## Description

Gets the current interrupt-time count, in a more precise form than [QueryInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryinterrupttime) does.

## Parameters

### `lpInterruptTimePrecise` [out]

A pointer to a ULONGLONG in which to receive the interrupt-time count in system time units of 100 nanoseconds. Divide by ten million, or 1e7, to get seconds (there are 1e9 nanoseconds in a second, so there are 1e7 100-nanoseconds in a second).

## Remarks

**QueryInterruptTimePrecise** is similar to the [QueryInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryinterrupttime) routine, but is more precise. The interrupt time reported by **QueryInterruptTime** is based on the latest tick of the system clock timer. The system clock timer is the hardware timer that periodically generates interrupts for the system clock. The uniform period between system clock timer interrupts is referred to as a system clock tick, and is typically in the range of 0.5 milliseconds to 15.625 milliseconds, depending on the hardware platform. The interrupt time value retrieved by **QueryInterruptTime** is accurate within a system clock tick.

To provide a system time value that is more precise than that of [QueryInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryinterrupttime), **QueryInterruptTimePrecise** reads the timer hardware directly, therefore a **QueryInterruptTimePrecise** call can be slower than a **QueryInterruptTime** call.

Call the [KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-kequerytimeincrement) routine to determine the duration of a system clock tick.

Also see Remarks in [QueryInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryinterrupttime).

**Note** The **QueryInterruptTimePrecise** function produces different results on debug ("checked") builds of Windows, because the interrupt-time count and tick count are advanced by approximately 49 days. This helps to identify bugs that might not occur until the system has been running for a long time.

To compile an application that uses this function, define _WIN32_WINNT as 0x0601 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Interrupt Time](https://learn.microsoft.com/windows/desktop/SysInfo/interrupt-time)

[QueryInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryinterrupttime)

[QueryUnbiasedInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttime)

[QueryUnbiasedInterruptTimePrecise](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttimeprecise)

[System Power States](https://learn.microsoft.com/windows/desktop/Power/system-power-states)

[Windows Time](https://learn.microsoft.com/windows/desktop/SysInfo/windows-time)