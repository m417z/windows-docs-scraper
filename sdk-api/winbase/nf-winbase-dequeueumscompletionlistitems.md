# DequeueUmsCompletionListItems function

## Description

Retrieves user-mode scheduling (UMS) worker threads from the specified UMS completion list.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `UmsCompletionList` [in]

A pointer to the completion list from which to retrieve worker threads.

### `WaitTimeOut` [in]

The time-out interval for the retrieval operation, in milliseconds. The function returns if the interval elapses, even if no worker threads are queued to the completion list.

If the *WaitTimeOut* parameter is zero, the completion list is checked for available worker threads without waiting for worker threads to become available. If the *WaitTimeOut* parameter is INFINITE, the function's time-out interval never elapses. This is not recommended, however, because it causes the function to block until one or more worker threads become available.

### `UmsThreadList` [out]

A pointer to a UMS_CONTEXT variable. On output, this parameter receives a pointer to the first UMS thread context in a list of UMS thread contexts.

If no worker threads are available before the time-out specified by the *WaitTimeOut* parameter, this parameter is set to NULL.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_TIMEOUT** | No threads became available before the specified time-out interval elapsed. |
| **ERROR_NOT_SUPPORTED** | UMS is not supported. |

## Remarks

The system queues a UMS worker thread to a completion list when the worker thread is created or when a previously blocked worker thread becomes unblocked. The **DequeueUmsCompletionListItems** function retrieves a pointer to a list of all thread contexts in the specified completion list. The [GetNextUmsListItem](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnextumslistitem) function can be used to pop UMS thread contexts off the list into the scheduler's own ready thread queue. The scheduler is responsible for selecting threads to run based on priorities chosen by the application.

Do not run UMS threads directly from the list provided by **DequeueUmsCompletionListItems**, or run a thread transferred from the list to the ready thread queue before the list is completely empty. This can cause unpredictable behavior in the application.

If more than one caller attempts to retrieve threads from a shared completion list, only the first caller retrieves the threads. For subsequent callers, the **DequeueUmsCompletionListItems** function returns success but the *UmsThreadList* parameter is set to NULL.

## See also

[GetNextUmsListItem](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnextumslistitem)