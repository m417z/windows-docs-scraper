# GetTickCount64 function

## Description

Retrieves the number of milliseconds that have elapsed since the system was started.

## Return value

The number of milliseconds.

## Remarks

The resolution of the **GetTickCount64** function is limited to the resolution of the system timer, which is typically in the range of 10 milliseconds to 16 milliseconds. The resolution of the **GetTickCount64** function is not affected by adjustments made by the
[GetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeadjustment) function.

If you need a higher resolution timer, use a
[multimedia timer](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timers) or a
[high-resolution timer](https://learn.microsoft.com/windows/desktop/winmsg/about-timers).

To obtain the time the system has spent in the working state since it was started, use the [QueryUnbiasedInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttime) function.

**Note** The [QueryUnbiasedInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttime) function produces different results on debug ("checked") builds of Windows, because the interrupt-time count and tick count are advanced by approximately 49 days. This helps to identify bugs that might not occur until the system has been running for a long time.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)

[Windows Time](https://learn.microsoft.com/windows/desktop/SysInfo/windows-time)