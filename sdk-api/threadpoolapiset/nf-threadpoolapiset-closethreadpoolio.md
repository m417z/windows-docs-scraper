# CloseThreadpoolIo function

## Description

Releases the specified I/O completion object.

## Parameters

### `pio` [in, out]

A pointer to a **TP_IO** structure that defines the I/O completion object. The [CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio) function returns this pointer.

## Remarks

The I/O completion object is freed immediately if there are no outstanding callbacks; otherwise, the I/O completion object is freed asynchronously after the outstanding callbacks complete.

You should close the associated file handle and wait for all outstanding overlapped I/O operations to complete before calling this function. You must not cause any more overlapped I/O operations to occur after calling this function.

It may be necessary to cancel threadpool I/O notifications to prevent memory leaks. For more information, see [CancelThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-cancelthreadpoolio).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CancelThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-cancelthreadpoolio)

[CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio)

[StartThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-startthreadpoolio)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolIoCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpooliocallbacks)