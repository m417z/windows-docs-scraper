# GetTickCount function

## Description

Retrieves the number of milliseconds that have elapsed since the system was started, up to 49.7 days.

## Return value

The return value is the number of milliseconds that have elapsed since the system was started.

## Remarks

The resolution of the **GetTickCount** function is limited to the resolution of the system timer, which is typically in the range of 10 milliseconds to 16 milliseconds. The resolution of the **GetTickCount** function is not affected by adjustments made by the
[GetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeadjustment) function.

The elapsed time is stored as a **DWORD** value. Therefore, the time will wrap around to zero if the system is run continuously for 49.7 days. To avoid this problem, use the [GetTickCount64](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-gettickcount64) function. Otherwise, check for an overflow condition when comparing times.

If you need a higher resolution timer, use a
[multimedia timer](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timers) or a
[high-resolution timer](https://learn.microsoft.com/windows/desktop/winmsg/about-timers).

To obtain the time elapsed since the computer was started, retrieve the System Up Time counter in the performance data in the registry key **HKEY_PERFORMANCE_DATA**. The value returned is an 8-byte value. For more information, see
[Performance Counters](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-counters-portal).

To obtain the time the system has spent in the working state since it was started, use the [QueryUnbiasedInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttime) function.

**Note** The [QueryUnbiasedInterruptTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryunbiasedinterrupttime) function produces different results on debug ("checked") builds of Windows, because the interrupt-time count and tick count are advanced by approximately 49 days. This helps to identify bugs that might not occur until the system has been running for a long time.

## Examples

```cpp
// calculate a 't' value that will linearly interpolate from 0 to 1 and back every 20 seconds
DWORD currentTime = GetTickCount();
if ( m_startTime == 0 )
{
    m_startTime = currentTime;
}
float t = 2 * (( currentTime - m_startTime) % 20000) / 20000.0f;
if (t > 1.0f)
{
    t = 2 - t;
}
```

## See also

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)

[Windows Time](https://learn.microsoft.com/windows/desktop/SysInfo/windows-time)