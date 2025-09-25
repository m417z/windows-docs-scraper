# PLOG_UNPINNED_CALLBACK callback function

## Description

The
**LOG_UNPINNED_CALLBACK** function is an application-defined callback function that receives notification that the log has become unpinned. The callback is invoked in the context of an asynchronous procedure call (APC) on the thread that registers for log management.

## Parameters

### `hLogFile` [in]

The handle to the log.

### `pvClientContext` [in]

A pointer to the client context. This is the same context specified when registering the client, which is a member of [LOG_MANAGEMENT_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/ns-clfsmgmtw32-log_management_callbacks).

## See also

[LOG_FULL_HANDLER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nc-clfsmgmtw32-plog_full_handler_callback)