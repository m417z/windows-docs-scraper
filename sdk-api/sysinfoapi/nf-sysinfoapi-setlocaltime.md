# SetLocalTime function

## Description

Sets the current local time and date.

## Parameters

### `lpSystemTime` [in]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the new local date and time.

The **wDayOfWeek** member of the
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure is ignored.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The calling process must have the SE_SYSTEMTIME_NAME privilege. This privilege is disabled by default. The
**SetLocalTime** function enables the SE_SYSTEMTIME_NAME privilege before changing the local time and disables the privilege before returning. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

The system uses UTC internally. Therefore, when you call
**SetLocalTime**, the system uses the current time zone information to perform the conversion, including the daylight saving time setting. Note that the system uses the daylight saving time setting of the current time, not the new time you are setting. Therefore, to ensure the correct result, call
**SetLocalTime** a second time, now that the first call has updated the daylight saving time setting.

## See also

[GetLocalTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlocaltime)

[GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime)

[Local Time](https://learn.microsoft.com/windows/desktop/SysInfo/local-time)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[SetSystemTimeAdjustment](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setsystemtimeadjustment)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)