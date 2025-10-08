# CancelIoEx function

Marks any outstanding I/O operations for the specified file handle. The function only cancels I/O operations in the current process, regardless of which thread created the I/O operation.

## Parameters

*hFile* \[in\]

A handle to the file.

*lpOverlapped* \[in, optional\]

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) data structure that contains the data used for asynchronous I/O.

If this parameter is **NULL**, all I/O requests for the *hFile* parameter are canceled.

If this parameter is not **NULL**, only those specific I/O requests that were issued for the file with the specified *lpOverlapped* overlapped structure are marked as canceled, meaning that you can cancel one or more requests, while the [**CancelIo**](https://learn.microsoft.com/windows/win32/fileio/cancelio) function cancels all outstanding requests on a file handle.

## Return value

If the function succeeds, the return value is nonzero. The cancel operation for all pending I/O operations issued by the calling process for the specified file handle was successfully requested. The application must not free or reuse the [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure associated with the canceled I/O operations until they have completed. The thread can use the [**GetOverlappedResult**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function to determine when the I/O operations themselves have been completed.

If the function fails, the return value is 0 (zero). To get extended error information, call the [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

If this function cannot find a request to cancel, the return value is 0 (zero), and [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR\_NOT\_FOUND**.

## Remarks

The **CancelIoEx** function allows you to cancel requests in threads other than the calling thread. The [**CancelIo**](https://learn.microsoft.com/windows/win32/fileio/cancelio) function only cancels requests in the same thread that called the **CancelIo** function. **CancelIoEx** cancels only outstanding I/O on the handle, it does not change the state of the handle; this means that you cannot rely on the state of the handle because you cannot know whether the operation was completed successfully or canceled.

If there are any pending I/O operations in progress for the specified file handle, the **CancelIoEx** function marks them for cancellation. Most types of operations can be canceled immediately; other operations can continue toward completion before they are actually canceled and the caller is notified. The **CancelIoEx** function does not wait for all canceled operations to complete.

If the file handle is associated with a completion port, an I/O completion packet is not queued to the port if a synchronous operation is successfully canceled. For asynchronous operations still pending, the cancel operation will queue an I/O completion packet.

The operation being canceled is completed with one of three statuses; you must check the completion status to determine the completion state. The three statuses are:

- The operation completed normally. This can occur even if the operation was canceled, because the cancel request might not have been submitted in time to cancel the operation.
- The operation was canceled. The [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR\_OPERATION\_ABORTED**.
- The operation failed with another error. The [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns the relevant error code.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
|------------------------------------------------------|----------------|
| Server Message Block (SMB) 3.0 protocol<br> | Yes<br> |
| SMB 3.0 Transparent Failover (TFO)<br> | Yes<br> |
| SMB 3.0 with Scale-out File Shares (SO)<br> | Yes<br> |
| Cluster Shared Volume File System (CsvFS)<br> | Yes<br> |
| Resilient File System (ReFS)<br> | Yes<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps \| UWP apps\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps \| UWP apps\]<br> |
| Header<br> | IoAPI.h (include Windows.h); <br>WinBase.h on Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista (include Windows.h) |
| Library<br> | Kernel32.lib |
| DLL<br> | Kernel32.dll |

## See also

[**CancelIo**](https://learn.microsoft.com/windows/win32/fileio/cancelio)

[**CancelSynchronousIo**](https://learn.microsoft.com/windows/win32/fileio/cancelsynchronousio-func)

[Canceling Pending I/O Operations](https://learn.microsoft.com/windows/win32/fileio/canceling-pending-i-o-operations)

[File Management Functions](https://learn.microsoft.com/windows/win32/fileio/file-management-functions)

[Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/win32/fileio/synchronous-and-asynchronous-i-o)

