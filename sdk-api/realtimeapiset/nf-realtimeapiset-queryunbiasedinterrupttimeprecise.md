# QueryUnbiasedInterruptTimePrecise function

## Description

Gets the current unbiased interrupt-time count, in a more precise form than [QueryUnbiasedInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttime) does. The unbiased interrupt-time count does not include time the system spends in sleep or hibernation.

## Parameters

### `lpUnbiasedInterruptTimePrecise` [out]

A pointer to a ULONGLONG in which to receive the unbiased interrupt-time count in system time units of 100 nanoseconds. Divide by ten million, or 1e7, to get seconds (there are 1e9 nanoseconds in a second, so there are 1e7 100-nanoseconds in a second).

## Remarks

**QueryUnbiasedInterruptTimePrecise** is similar to the [QueryUnbiasedInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttime) routine, but is more precise. The interrupt time reported by **QueryUnbiasedInterruptTime** is based on the latest tick of the system clock timer. The system clock timer is the hardware timer that periodically generates interrupts for the system clock. The uniform period between system clock timer interrupts is referred to as a system clock tick, and is typically in the range of 0.5 milliseconds to 15.625 milliseconds, depending on the hardware platform. The interrupt time value retrieved by **QueryUnbiasedInterruptTime** is accurate within a system clock tick.

To provide a system time value that is more precise than that of [QueryUnbiasedInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttime), **QueryUnbiasedInterruptTimePrecise** reads the timer hardware directly, therefore a **QueryUnbiasedInterruptTimePrecise** call can be slower than a **QueryUnbiasedInterruptTime** call.

Call the [KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-kequerytimeincrement) routine to determine the duration of a system clock tick.

Also see Remarks in [QueryUnbiasedInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttime).

**Note** The **QueryUnbiasedInterruptTimePrecise** function produces different results on debug ("checked") builds of Windows, because the interrupt-time count and tick count are advanced by approximately 49 days. This helps to identify bugs that might not occur until the system has been running for a long time.

To compile an application that uses this function, define _WIN32_WINNT as 0x0601 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Interrupt Time](https://learn.microsoft.com/windows/desktop/SysInfo/interrupt-time)

[QueryInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryinterrupttime)

[QueryInterruptTimePrecise](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryinterrupttimeprecise)

[QueryUnbiasedInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttime)

[System Power States](https://learn.microsoft.com/windows/desktop/Power/system-power-states)

[Windows Time](https://learn.microsoft.com/windows/desktop/SysInfo/windows-time)