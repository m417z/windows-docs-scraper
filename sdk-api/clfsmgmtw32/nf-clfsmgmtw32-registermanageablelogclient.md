# RegisterManageableLogClient function

## Description

The **RegisterManageableLogClient** function registers a client with the log manager. A client can specify whether to receive notifications by using callbacks, or have the notifications queued for retrieval by using [ReadLogNotification](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-readlognotification).

## Parameters

### `hLog` [in]

The handle to the log to register. Only one registration per unique opening of the log is allowed.

### `pCallbacks` [in]

Specifies the callbacks that the client is registering for. Valid callbacks are enumerated by [LOG_MANAGEMENT_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/ns-clfsmgmtw32-log_management_callbacks). Specify zero to queue notifications instead.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A client can deregister either by closing the log handle, or by calling [DeregisterManageableLogClient](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-deregistermanageablelogclient).

#### Examples

For an example that uses this function, see [Creating a Log File](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/creating-a-log-file).

## See also

[DeregisterManageableLogClient](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-deregistermanageablelogclient)

[LOG_MANAGEMENT_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/ns-clfsmgmtw32-log_management_callbacks)