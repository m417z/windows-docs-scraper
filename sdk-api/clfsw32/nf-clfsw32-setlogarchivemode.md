# SetLogArchiveMode function

## Description

Enables or disables log archive support for a specified log.

## Parameters

### `hLog` [in]

A handle to the log that is obtained from
[CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile).

### `eMode` [in]

Specifies whether to make the log ephemeral. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ClfsLogArchiveEnabled** | Enable log archive (ephemeral logs) support. |
| **ClfsLogArchiveDisabled** | Disables ephemeral logs. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)