# CancelSynchronousIo function

## Description

Marks pending synchronous I/O operations that are issued by the specified thread as
canceled.

## Parameters

### `hThread` [in]

A handle to the thread.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

If this function cannot find a request to cancel, the return value is 0 (zero), and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_NOT_FOUND**.

## Remarks

The caller must have the
[THREAD_TERMINATE](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights) access right.

If there are any pending I/O operations in progress for the specified thread, the
**CancelSynchronousIo** function marks them for
cancellation. Most types of operations can be canceled immediately; other operations can continue toward
completion before they are actually canceled and the caller is notified. The
**CancelSynchronousIo** function does not wait for
all canceled operations to complete. For more information, see
[Canceling Pending I/O Operations](https://learn.microsoft.com/en-us/windows/win32/fileio/canceling-pending-i-o-operations).

The operation being canceled is completed with one of three statuses; you must check the completion status to
determine the completion state. The three statuses are:

* **The operation completed normally.** This can occur even if the operation was
  canceled, because the cancel request might not have been submitted in time to cancel the operation.
* **The operation was canceled.** The
  [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns
  **ERROR_OPERATION_ABORTED**.
* **The operation failed with another error.** The
  [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns the relevant error
  code.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[CancelIo](https://learn.microsoft.com/windows/desktop/FileIO/cancelio)

[CancelIoEx](https://learn.microsoft.com/windows/desktop/FileIO/cancelioex-func)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/desktop/FileIO/synchronous-and-asynchronous-i-o)