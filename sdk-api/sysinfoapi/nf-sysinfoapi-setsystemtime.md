# SetSystemTime function

## Description

Sets the current system time and date. The system time is expressed in Coordinated Universal Time (UTC).

## Parameters

### `lpSystemTime` [in]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the new system date and time.

The **wDayOfWeek** member of the
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure is ignored.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The calling process must have the SE_SYSTEMTIME_NAME privilege. This privilege is disabled by default. The
**SetSystemTime** function enables the SE_SYSTEMTIME_NAME privilege before changing the system time and disables the privilege before returning. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

## See also

[GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[SetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setsystemtimeadjustment)

[System Time](https://learn.microsoft.com/windows/desktop/SysInfo/system-time)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)