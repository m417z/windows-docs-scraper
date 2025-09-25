# PLOG_FULL_HANDLER_CALLBACK callback function

## Description

The
**LOG_FULL_HANDLER_CALLBACK** function is an application-defined callback function that receives notification that the call to [HandleLogFull](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-handlelogfull) is complete. The callback is invoked in the context of an asynchronous procedure call (APC) on the thread that registered for log management.

## Parameters

### `hLogFile` [in]

The handle to the log.

### `dwError` [in]

The status of the operation.

### `fLogIsPinned` [in]

Specifies if the log is considered "pinned". If *fLogIsPinned* is **TRUE** and the log is then unpinned, the [LOG_UNPINNED_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nc-clfsmgmtw32-plog_unpinned_callback) is invoked.

### `pvClientContext` [in]

A pointer to the client context.

## Remarks

The client application determines which actions this callback function performs.

## See also

[LOG_UNPINNED_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nc-clfsmgmtw32-plog_unpinned_callback)