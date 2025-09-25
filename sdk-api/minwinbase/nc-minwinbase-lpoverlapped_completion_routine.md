## Description

An application-defined callback function used with the
[ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex) and
[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex) functions. It is called when the asynchronous
input and output (I/O) operation is completed or canceled and the calling thread is in an alertable
state (by using the [SleepEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-sleepex),
[MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex),
[WaitForSingleObjectEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobjectex), or
[WaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjectsex) function with the
*fAlertable* parameter set to **TRUE**).

The **LPOVERLAPPED_COMPLETION_ROUTINE** type defines a pointer to this callback
function. **FileIOCompletionRoutine** is a
placeholder for the application-defined function name.

## Parameters

### `dwErrorCode` [in]

The I/O completion status. This parameter can be one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

### `dwNumberOfBytesTransfered` [in]

The number of bytes transferred. If an error occurs, this parameter is zero.

### `lpOverlapped` [in, out]

A pointer to the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure specified by
the asynchronous I/O function.

The system does not use the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure
after the completion routine is called, so the completion routine can deallocate the memory used by the
overlapped structure.

## Remarks

The return value for an asynchronous operation is 0 (**ERROR_SUCCESS**) if the operation
completed successfully or if the operation completed with a warning. To determine whether an I/O operation was
completed successfully, check that *dwErrorCode* is 0, call
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult), then call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). For example, if the buffer was not large
enough to receive all of the data from a call to [ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex),
*dwErrorCode* is set to 0,
**GetOverlappedResult** fails, and
**GetLastError** returns
**ERROR_MORE_DATA**.

Returning from this function allows another pending I/O completion routine to be called. All waiting
completion routines are called before the alertable thread's wait is completed with a return code of
**WAIT_IO_COMPLETION**. The system may call the waiting completion routines in any order.
They may or may not be called in the order the I/O functions are completed.

Each time the system calls a completion routine, it uses some of the application's stack. If the completion
routine does additional asynchronous I/O and alertable waits, the stack may grow.

For more information, see
[Asynchronous Procedure Calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls).

## Examples

For example code, see
[Named Pipe Server Using Completion Routines](https://learn.microsoft.com/windows/desktop/ipc/named-pipe-server-using-completion-routines).

## See also

[BindIoCompletionCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-bindiocompletioncallback)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex)

[SleepEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-sleepex)

[Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/desktop/FileIO/synchronous-and-asynchronous-i-o)

[WaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjectsex)

[WaitForSingleObjectEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobjectex)

[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex)