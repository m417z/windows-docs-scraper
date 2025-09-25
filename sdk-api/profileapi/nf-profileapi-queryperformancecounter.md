# QueryPerformanceCounter function

## Description

Retrieves the current value of the performance counter, which is a high resolution (<1us) time stamp that can be used for time-interval measurements.

## Parameters

### `lpPerformanceCount` [out]

A pointer to a variable that receives the current performance-counter value, in counts.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). On systems that run Windows XP or later, the function will always succeed and will thus never return zero.

## Remarks

For more info about this function and its usage, see [Acquiring high-resolution time stamps](https://learn.microsoft.com/windows/desktop/SysInfo/acquiring-high-resolution-time-stamps).

## Examples

```cpp
// Gets the current number of ticks from QueryPerformanceCounter. Throws an
// exception if the call to QueryPerformanceCounter fails.
static inline int64_t GetTicks()
{
    LARGE_INTEGER ticks;
    if (!QueryPerformanceCounter(&ticks))
    {
        winrt::throw_last_error();
    }
    return ticks.QuadPart;
}
```

## See also

[Acquiring high-resolution time stamps](https://learn.microsoft.com/windows/desktop/SysInfo/acquiring-high-resolution-time-stamps)

**Conceptual**

[GetSystemTimePreciseAsFileTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimepreciseasfiletime)

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/nf-ntifs-kequeryperformancecounter)

[QueryPerformanceFrequency](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancefrequency)

**Reference**

[Time](https://learn.microsoft.com/windows/desktop/SysInfo/time)

[Timers](https://learn.microsoft.com/windows/win32/winmsg/timers)