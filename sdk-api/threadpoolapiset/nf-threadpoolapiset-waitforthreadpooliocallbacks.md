# WaitForThreadpoolIoCallbacks function

## Description

Waits for outstanding I/O completion callbacks to complete and optionally cancels pending callbacks that have not yet started to execute.

## Parameters

### `pio` [in, out]

A pointer to a **TP_IO** structure that defines the I/O completion object. The [CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio) function returns this pointer.

### `fCancelPendingCallbacks` [in]

Indicates whether to cancel queued callbacks that have not yet started to execute.

## Remarks

When *fCancelPendingCallbacks* is set to TRUE, only queued callbacks are canceled. Pending I/O requests are not canceled. Therefore, the caller should call [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) for the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure to check whether the I/O operation has completed before freeing the structure. As an alternative, set *fCancelPendingCallbacks* to FALSE and have the associated I/O completion callback free the **OVERLAPPED** structure. Be careful not to free the **OVERLAPPED** structure while I/O requests are still pending; use **GetOverlappedResult** to determine the status of the I/O operation and wait for the operation to complete. The [CancelIoEx](https://learn.microsoft.com/windows/desktop/FileIO/cancelioex-func) function can optionally be used first to cancel outstanding I/O requests, potentially shortening the wait. For more information, see [Canceling Pending I/O Operations](https://learn.microsoft.com/windows/desktop/FileIO/canceling-pending-i-o-operations).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CancelThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-cancelthreadpoolio)

[CloseThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolio)

[CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio)

[StartThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-startthreadpoolio)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)