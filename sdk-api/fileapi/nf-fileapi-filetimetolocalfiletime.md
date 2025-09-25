# FileTimeToLocalFileTime function

## Description

Converts a file time to a local file time.

## Parameters

### `lpFileTime` [in]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the UTC-based file time to be converted into a local file time.

### `lpLocalFileTime` [out]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure to receive the converted local file time. This parameter cannot be the same as the *lpFileTime* parameter.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To account for daylight saving time when converting a file time to a local time, use the following sequence of functions in place of using **FileTimeToLocalFileTime**:

1. [FileTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-filetimetosystemtime)
2. [SystemTimeToTzSpecificLocalTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-systemtimetotzspecificlocaltime)
3. [SystemTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-systemtimetofiletime)

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times)

[LocalFileTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-localfiletimetofiletime)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)