# CompareFileTime function

## Description

Compares two file times.

## Parameters

### `lpFileTime1` [in]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies the
first file time.

### `lpFileTime2` [in]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies the
second file time.

## Return value

The return value is one of the following values.

| Return value | Description |
| --- | --- |
| -1 | First file time is earlier than second file time. |
| 0 | First file time is equal to second file time. |
| 1 | First file time is later than second file time. |

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times)

[GetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfiletime)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)