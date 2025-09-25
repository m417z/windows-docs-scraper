# HandleLogFull function

## Description

The **HandleLogFull** function is called by a managed log client when an attempt to reserve or append to a log fails with a log full error message. The log manager attempts to resolve the log full condition for the client, and notifies the client when the outcome is known. As a result of this call, the log may get larger in size.

## Parameters

### `hLog` [in]

A handle to the log on which to resolve the log full condition. The handle must have been registered with [RegisterManageableLogClient](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-registermanageablelogclient).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Valid values include the following:

## Remarks

If containers are created to resolve a log-full condition, they are created using the calling application's security context.

**HandleLogFull** always results in asynchronous behavior or an error; if it returns false and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_IO_PENDING**, the result is asynchronous behavior. If a request is asynchronous, a notification is sent to the client when the handler has either resolved the log full condition or it fails.