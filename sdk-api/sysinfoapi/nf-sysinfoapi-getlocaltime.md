# GetLocalTime function

## Description

Retrieves the current local date and time.

To retrieve the current date and time in Coordinated Universal Time (UTC) format, use the [GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime) function.

## Parameters

### `lpSystemTime` [out]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure to receive the current local date and time.

## Remarks

To set the current local date and time, use the [SetLocalTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setlocaltime) function.

#### Examples

For an example, see
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime).

## See also

[GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime)

[Local Time](https://learn.microsoft.com/windows/desktop/SysInfo/local-time)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[SetLocalTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setlocaltime)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)