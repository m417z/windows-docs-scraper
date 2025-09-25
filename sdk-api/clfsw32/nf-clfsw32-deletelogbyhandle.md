# DeleteLogByHandle function

## Description

Marks the specified log for deletion. The log is actually deleted when all handles, marshaling areas, and read contexts to the log are closed. If the log is a physical log, its underlying containers are deleted.

When a log is marked for deletion, requests to open new client log streams fail.

**Note** This function differs from [DeleteLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-deletelogfile), because it takes a valid open handle to the log object instead of the log name.

## Parameters

### `hLog` [in]

A handle to an open log that is obtained by a successful call to [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile). The log must have been created with DELETE access or you cannot delete the log.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## See also

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile)

[DeleteLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-deletelogfile)