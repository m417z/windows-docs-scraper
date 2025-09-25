# SERVICE_TIMECHANGE_INFO structure

## Description

Contains system time change settings.

## Members

### `liNewTime`

The new system time.

### `liOldTime`

The previous system time.

## Remarks

The time values in the *liNewTime* and *liOldTime* members cannot be used directly with the time functions, which typically require a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) or [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure. Convert the [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) structure to a [ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer~r1) structure, copy the **ULARGE_INTEGER** structure to a **FILETIME** structure, and then if necessary use the [FileTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-filetimetosystemtime) function to convert the **FILETIME** structure to a **SYSTEMTIME** structure.

## See also

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)