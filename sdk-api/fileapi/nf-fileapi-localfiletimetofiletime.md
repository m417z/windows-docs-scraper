# LocalFileTimeToFileTime function

## Description

Converts a local file time to a file time based on the Coordinated Universal Time (UTC).

## Parameters

### `lpLocalFileTime` [in]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies the
local file time to be converted into a UTC-based file time.

### `lpFileTime` [out]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure to receive the
converted UTC-based file time. This parameter cannot be the same as the
*lpLocalFileTime* parameter.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

**LocalFileTimeToFileTime** uses the current
settings for the time zone and daylight saving time. Therefore, if it is daylight saving time, this function will
take daylight saving time into account, even if the time you are converting is in standard time.

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[FileTimeToLocalFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-filetimetolocalfiletime)

[Local Time](https://learn.microsoft.com/windows/desktop/SysInfo/local-time)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)