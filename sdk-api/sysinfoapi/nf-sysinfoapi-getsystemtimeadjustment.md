# GetSystemTimeAdjustment function

## Description

Determines whether the system is applying periodic time adjustments to its time-of-day clock, and obtains the value and period of any such adjustments.

## Parameters

### `lpTimeAdjustment` [out]

A pointer to a variable that the function sets to the number of *lpTimeIncrement* 100-nanosecond units added to the time-of-day clock for every period of time which actually passes as counted by the system. This value only has meaning if *lpTimeAdjustmentDisabled* is **FALSE**.

### `lpTimeIncrement` [out]

A pointer to a variable that the function sets to the interval in 100-nanosecond units at which the system will add *lpTimeAdjustment* to the time-of-day clock. This value only has meaning if *lpTimeAdjustmentDisabled* is **FALSE**.

### `lpTimeAdjustmentDisabled` [out]

A pointer to a variable that the function sets to indicate whether periodic time adjustment is in effect.

A value of **TRUE** indicates that periodic time adjustment is disabled, and the system time-of-day clock advances at the normal rate. In this mode, the system may adjust the time of day using its own internal time synchronization mechanisms. These internal time synchronization mechanisms may cause the time-of-day clock to change during the normal course of the system operation, which can include noticeable jumps in time as deemed necessary by the system.

A value of **FALSE** indicates that periodic time adjustment is being used to adjust the time-of-day clock. For each *lpTimeIncrement* period of time that actually passes, *lpTimeAdjustment* will be added to the time of day. If the *lpTimeAdjustment* value is smaller than *lpTimeIncrement*, the system time-of-day clock will advance at a rate slower than normal. If the *lpTimeAdjustment* value is larger than *lpTimeIncrement*, the time-of-day clock will advance at a rate faster than normal. If *lpTimeAdjustment* equals *lpTimeIncrement*, the time-of-day clock will advance at its normal speed. The *lpTimeAdjustment* value can be set by calling [SetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setsystemtimeadjustment). The *lpTimeIncrement* value is fixed by the system upon start, and does not change during system operation. In this mode, the system will not interfere with the time adjustment scheme, and will not attempt to synchronize time of day on its own via other techniques.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetSystemTimeAdjustment** and [SetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setsystemtimeadjustment) functions can be used to support algorithms that want to synchronize the time-of-day clock, reported by [GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime) and [GetLocalTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlocaltime), with another time source by using a periodic time adjustment.

The **GetSystemTimeAdjustment** function lets a caller determine whether periodic time adjustment is enabled, and if it is, obtain the amount of each adjustment and the time between adjustments. The [SetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setsystemtimeadjustment) function lets a caller enable or disable periodic time adjustment, and set the value of the adjusting increment.

## See also

[GetLocalTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlocaltime)

[GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime)

[SetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setsystemtimeadjustment)

[System Time](https://learn.microsoft.com/windows/desktop/SysInfo/system-time)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)