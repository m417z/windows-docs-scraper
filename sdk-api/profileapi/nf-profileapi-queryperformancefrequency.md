# QueryPerformanceFrequency function

## Description

Retrieves the frequency of the performance counter. The frequency of the performance counter is fixed at system boot and is consistent across all processors. Therefore, the frequency need only be queried upon application initialization, and the result can be cached.

## Parameters

### `lpFrequency` [out]

A pointer to a variable that receives the current performance-counter frequency, in counts per second. If the installed hardware doesn't support a high-resolution performance counter, this parameter can be zero (this will not occur on systems that run Windows XP or later).

## Return value

If the installed hardware supports a high-resolution performance counter, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). On systems that run Windows XP or later, the function will always succeed and will thus never return zero.

## Remarks

For more info about this function and its usage, see [Acquiring high-resolution time stamps](https://learn.microsoft.com/windows/desktop/SysInfo/acquiring-high-resolution-time-stamps).

## See also

[Acquiring high-resolution time stamps](https://learn.microsoft.com/windows/desktop/SysInfo/acquiring-high-resolution-time-stamps)

**Conceptual**

[GetSystemTimePreciseAsFileTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimepreciseasfiletime)

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/nf-ntifs-kequeryperformancecounter)

[QueryPerformanceCounter](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter)

**Reference**

[Time](https://learn.microsoft.com/windows/desktop/SysInfo/time)

[Timers](https://learn.microsoft.com/windows/win32/winmsg/timers)