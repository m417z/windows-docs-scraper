# BindIoCompletionCallback function

## Description

Associates the I/O completion port owned by the [thread pool](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pooling) with the specified file handle. On completion of an I/O request involving this file, a non-I/O worker thread will execute the specified callback function.

## Parameters

### `FileHandle` [in]

A handle to the file opened for overlapped I/O completion. This handle is returned by the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function, with the **FILE_FLAG_OVERLAPPED** flag.

### `Function` [in]

A pointer to the callback function to be executed in a non-I/O worker thread when the I/O operation is complete. This callback function must not call the
[TerminateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminatethread) function.

For more information about the completion routine, see
[FileIOCompletionRoutine](https://learn.microsoft.com/windows/desktop/api/minwinbase/nc-minwinbase-lpoverlapped_completion_routine).

### `Flags` [in]

This parameter must be zero.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The callback function might not be executed if the process issues an asynchronous request on the file specified by the *FileHandle* parameter but the request returns immediately with an error code other than ERROR_IO_PENDING.

Be sure that the thread that initiates the asynchronous I/O request does not terminate before the request is completed. Also, if a function in a DLL is queued to a worker thread, be sure that the function in the DLL has completed execution before the DLL is unloaded.

The thread pool maintains an I/O completion port. When you call **BindIoCompletionCallback**, it associates the specified file with the thread pool's I/O completion port. Asynchronous requests on that file object will complete by posting to the completion port, where they will be picked up by thread pool worker threads. For callbacks that must issue an I/O request that completes as an asynchronous procedure call, the thread pool provides an I/O worker pool. The I/O worker threads do not wait on the completion port; they sleep in an alertable wait state so that I/O request packets that complete can wake them up. Both types of worker threads check whether there is I/O pending on them and if there is, they do not exit. For more information, see [Asynchronous Procedure Calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls).

To compile an application that uses this function, define _WIN32_WINNT as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[FileIOCompletionRoutine](https://learn.microsoft.com/windows/desktop/api/minwinbase/nc-minwinbase-lpoverlapped_completion_routine)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Thread Pooling](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pooling)