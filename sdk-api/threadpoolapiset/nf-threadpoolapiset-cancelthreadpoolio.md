# CancelThreadpoolIo function

## Description

Cancels the notification from the [StartThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-startthreadpoolio) function.

## Parameters

### `pio` [in, out]

A pointer to a **TP_IO** structure that defines the I/O completion object. The [CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio) function returns this pointer.

## Remarks

To prevent memory leaks, you must call the **CancelThreadpoolIo** function for either of the following scenarios:

* An overlapped (asynchronous) I/O operation fails (that is, the asynchronous I/O function call returns failure with an error code other than ERROR_IO_PENDING).
* An asynchronous I/O operation returns immediately with success and the file handle associated with the I/O completion object has the notification mode FILE_SKIP_COMPLETION_PORT_ON_SUCCESS. The file handle will not notify the I/O completion port and the associated I/O callback function will not be called.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CloseThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolio)

[CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio)

[StartThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-startthreadpoolio)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolIoCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpooliocallbacks)