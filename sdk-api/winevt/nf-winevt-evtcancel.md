# EvtCancel function

## Description

Cancels all pending operations on a handle.

## Parameters

### `Object`

The handle whose operation you want to cancel. You can cancel the following operations:

* [EvtClearLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclearlog)
* [EvtExportLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtexportlog)
* [EvtNext](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnext)
* [EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery)
* [EvtSeek](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtseek)
* [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe)

To cancel the [EvtClearLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclearlog),
[EvtExportLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtexportlog),
[EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery), and
[EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) operations, you must pass the session
handle. To specify the default session (local session), set this parameter to
**NULL**.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## Remarks

Use this function to cancel long-running operations. For example, calling the
[EvtNext](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnext) function could theoretically take a long time due to
the filtering of thousands of event records. Calling
**EvtCancel** would stop the
**EvtNext** function from processing further event records. Note
that the function may not be able to stop the operation immediately.

You must call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function to close the handle
when done.

The following procedure describes how to cancel a long-running operation.

**To cancel a long-running operation**

1. Thread A calls a long running operation (for example, the
   [EvtSeek](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtseek) function).
2. Thread B wants to cancel and close all operations, so thread B calls the
   **EvtCancel** function.
3. Thread B then waits for all pending calls to complete (by synchronizing with thread A). Because the
   **EvtCancel** function was called, thread A should complete
   soon after the call to the **EvtCancel** was made.
4. After thread A has fully completed the operation
   ([EvtSeek](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtseek)), thread B can close the query result handle using
   the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function.

The operation being stopped will return with an error code of ERROR_CANCELLED.