# timeGetTime function

## Description

The **timeGetTime** function retrieves the system time, in milliseconds. The system time is the time elapsed since Windows was started.

## Return value

Returns the system time, in milliseconds.

## Remarks

The only difference between this function and the [timeGetSystemTime](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timegetsystemtime) function is that **timeGetSystemTime** uses the [MMTIME](https://learn.microsoft.com/previous-versions/dd757347(v=vs.85)) structure to return the system time. The **timeGetTime** function has less overhead than **timeGetSystemTime**.

Note that the value returned by the **timeGetTime** function is a **DWORD** value. The return value wraps around to 0 every 2^32 milliseconds, which is about 49.71 days. This can cause problems in code that directly uses the **timeGetTime** return value in computations, particularly where the value is used to control code execution. You should always use the difference between two **timeGetTime** return values in computations.

The default precision of the **timeGetTime** function can be five milliseconds or more, depending on the machine. You can use the [timeBeginPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timebeginperiod) and [timeEndPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timeendperiod) functions to increase the precision of **timeGetTime**. If you do so, the minimum difference between successive values returned by **timeGetTime** can be as large as the minimum period value set using **timeBeginPeriod** and **timeEndPeriod**. Use the [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter) and [QueryPerformanceFrequency](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancefrequency) functions to measure short time intervals at a high resolution.

## See also

[Multimedia Timer Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timer-functions)

[Multimedia Timers](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timers)