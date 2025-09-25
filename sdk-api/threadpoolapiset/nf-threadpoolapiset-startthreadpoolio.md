# StartThreadpoolIo function

## Description

Notifies the thread pool that I/O operations may possibly begin for the specified I/O completion object. A worker thread calls the I/O completion object's callback function after the operation completes on the file handle bound to this object.

## Parameters

### `pio` [in, out]

A pointer to a **TP_IO** structure that defines the I/O completion object. The [CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio) function returns this pointer.

## Remarks

You must call this function before initiating each asynchronous I/O operation on the file handle bound to the I/O completion object. Failure to do so will cause the thread pool to ignore an I/O operation when it completes and will cause memory corruption.

If the I/O operation fails, call the [CancelThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-cancelthreadpoolio) function to cancel this notification.

If the file handle bound to the I/O completion object has the notification mode FILE_SKIP_COMPLETION_PORT_ON_SUCCESS and an asynchronous I/O operation returns immediately with success, the object's I/O completion callback function is not called and threadpool I/O notifications must be canceled. For more information, see [CancelThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-cancelthreadpoolio).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CancelThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-cancelthreadpoolio)

[CloseThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolio)

[CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolIoCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpooliocallbacks)