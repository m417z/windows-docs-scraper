# SetSystemTimeAdjustment function

## Description

Enables or disables periodic time adjustments to the system's time-of-day clock. When enabled, such time adjustments can be used to synchronize the time of day with some other source of time information.

## Parameters

### `dwTimeAdjustment` [in]

This value represents the number of 100-nanosecond units added to the system time-of-day for each *lpTimeIncrement* period of time that actually passes. Call [GetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeadjustment) to obtain the *lpTimeIncrement* value. See remarks.

**Note**

Currently, Windows Vista and Windows 7 machines will lose any time adjustments set less than 16.

### `bTimeAdjustmentDisabled` [in]

The time adjustment mode that the system is to use. Periodic system time adjustments can be disabled or enabled.

A value of **TRUE** specifies that periodic time adjustment is to be disabled. When disabled, the value of *dwTimeAdjustment* is ignored, and the system may adjust the time of day using its own internal time synchronization mechanisms. These internal time synchronization mechanisms may cause the time-of-day clock to change during the normal course of the system operation, which can include noticeable jumps in time as deemed necessary by the system.

A value of **FALSE** specifies that periodic time adjustment is to be enabled, and will be used to adjust the time-of-day clock. The system will not interfere with the time adjustment scheme, and will not attempt to synchronize time of day on its own.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). One way the function can fail is if the caller does not possess the SE_SYSTEMTIME_NAME privilege.

## Remarks

The
[GetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeadjustment) and
**SetSystemTimeAdjustment** functions support algorithms that synchronize the time-of-day clock, reported via
[GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime) and
[GetLocalTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlocaltime), with another time source using a periodic time adjustment.

The
**SetSystemTimeAdjustment** function supports two modes of time synchronization:

| Mode | Behavior |
| --- | --- |
| Time-Adjustment Disabled | For this mode, *bTimeAdjustmentDisabled* is set to **TRUE**. In this mode, the value of *dwTimeAdjustment* is ignored, and the system may adjust the time of day using its own internal time synchronization mechanisms. These internal time synchronization mechanisms may cause the time-of-day clock to change during the normal course of the system operation, which can include noticeable jumps in time as deemed necessary by the system. |
| Time-Adjustment Enabled | For this mode, *bTimeAdjustmentDisabled* is set to **FALSE**. For each *lpTimeIncrement* period of time that actually passes, *dwTimeAdjustment* will be added to the time of day. The period of time represented by *lpTimeIncrement* can be determined by calling [GetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeadjustment). The *lpTimeIncrement* value is fixed by the system upon start and does not change during system operation and is completely independent of the system’s internal clock interrupt resolution at any given time. Given this, the *lpTimeIncrement* value simply expresses a period of time for which *dwTimeAdjustment* will be applied to the system’s time-of-day clock.<br><br>If the *dwTimeAdjustment* value is smaller than *lpTimeIncrement*, the time-of-day clock will advance at a rate slower than normal. If the *dwTimeAdjustment* value is larger than *lpTimeIncrement*, the time-of-day clock will advance at a rate faster than normal. The degree to which the time-of-day-clock will run faster or slower depends on how far the *dwTimeAdjustment* value is above or below the *lpTimeIncrement* value. If *dwTimeAdjustment* equals *lpTimeIncrement*, the time-of-day clock will advance at normal speed. |

An application must have system-time privilege (the SE_SYSTEMTIME_NAME privilege) for this function to succeed. The SE_SYSTEMTIME_NAME privilege is disabled by default. Use the
[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) function to enable the privilege before calling
**SetSystemTimeAdjustment**, and then to disable the privilege after the
**SetSystemTimeAdjustment** call. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

## See also

[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges)

[GetLocalTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlocaltime)

[GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime)

[GetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeadjustment)

[System Time](https://learn.microsoft.com/windows/desktop/SysInfo/system-time)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)