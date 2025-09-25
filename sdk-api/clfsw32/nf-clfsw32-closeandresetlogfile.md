# CloseAndResetLogFile function

## Description

Resets the log file and then shuts the log. This nullifies any client restart areas and resets the base log sequence number (LSN) for the log. You do not need to close a log stream handle after calling this function.

## Parameters

### `hLog` [in]

A handle to a dedicated or multiplexed log.

This handle is returned by a successful call to [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile). It is invalidated on successful completion of the call. No other operations that use this handle, or a derivative of this handle, can be called after this function has returned.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## See also

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile)