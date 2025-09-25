# QueryInterruptTime function

## Description

Gets the current interrupt-time count. For a more precise count, use [QueryInterruptTimePrecise](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryinterrupttimeprecise).

## Parameters

### `lpInterruptTime` [out]

A pointer to a ULONGLONG in which to receive the interrupt-time count in system time units of 100 nanoseconds. Divide by ten million, or 1e7, to get seconds (there are 1e9 nanoseconds in a second, so there are 1e7 100-nanoseconds in a second).

## Remarks

The interrupt-time count begins at zero when the system starts and is incremented at each clock interrupt by the length of a clock tick. The exact length of a clock tick depends on underlying hardware and can vary between systems.

Unlike system time, the interrupt-time count is not subject to adjustments by users or the Windows time service. Applications can use the interrupt-time count to measure finer durations than are possible with system time. Applications that require greater precision than the interrupt-time count should use a [high-resolution timer](https://learn.microsoft.com/windows/desktop/winmsg/about-timers). Use the [QueryPerformanceFrequency](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancefrequency) function to retrieve the frequency of the high-resolution timer and the [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter) function to retrieve the counter's value.

The timer resolution set by the [timeBeginPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timebeginperiod) and [timeEndPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timeendperiod) functions affects the resolution of the **QueryInterruptTime** function. However, increasing the timer resolution is not recommended because it can reduce overall system performance and increase system power consumption by preventing the processor from entering power-saving states. Instead, applications should use a high-resolution timer.

**Note** The **QueryInterruptTime** function produces different results on debug ("checked") builds of Windows, because the interrupt-time count and tick count are advanced by approximately 49 days. This helps to identify bugs that might not occur until the system has been running for a long time.

To compile an application that uses this function, define _WIN32_WINNT as 0x0601 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Interrupt Time](https://learn.microsoft.com/windows/desktop/SysInfo/interrupt-time)

[QueryInterruptTimePrecise](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryinterrupttimeprecise)

[QueryUnbiasedInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttime)

[QueryUnbiasedInterruptTimePrecise](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttimeprecise)

[System Power States](https://learn.microsoft.com/windows/desktop/Power/system-power-states)

[Windows Time](https://learn.microsoft.com/windows/desktop/SysInfo/windows-time)