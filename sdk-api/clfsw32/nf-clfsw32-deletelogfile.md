# DeleteLogFile function

## Description

Marks a log for deletion. The log is actually deleted when all handles, marshaling areas, and read contexts to the log are closed. If the log is a physical log, its underlying containers are deleted.

When a log is marked for deletion, requests to open new client log streams fail.

**Note** A closely related function is [DeleteLogByHandle](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-deletelogbyhandle), which deletes a log when given the handle of the file.

## Parameters

### `pszLogFileName` [in]

The name of the log.

This name is specified when creating the log by using [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile). The following example identifies the format to use:

**log:<***log name***>[::<***log stream name***>]**

<*log name*> corresponds to a valid file path in the file system.

<*log stream name*> is the unique name of a log stream in the log.

 For more information, see [Log Types](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/log-types).

### `pvReserved` [in, optional]

This parameter is reserved and should be set to **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## See also

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile)

[DeleteLogByHandle](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-deletelogbyhandle)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)