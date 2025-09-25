# GetOverlappedResultEx function

## Description

Retrieves the results of an overlapped operation on the specified file, named pipe, or communications device within the specified time-out interval. The calling thread can perform an alertable wait.

## Parameters

### `hFile` [in]

A handle to the file, named pipe, or communications device. This is the same handle that was specified when the overlapped operation was started by a call to the
[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile),
[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile),
[ConnectNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe),
[TransactNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe),
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol), or
[WaitCommEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitcommevent) function.

### `lpOverlapped` [in]

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that was specified when the overlapped operation was started.

### `lpNumberOfBytesTransferred` [out]

A pointer to a variable that receives the number of bytes that were actually transferred by a read or write operation. For a
[TransactNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe) operation, this is the number of bytes that were read from the pipe. For a
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) operation, this is the number of bytes of output data returned by the device driver. For a
[ConnectNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe) or
[WaitCommEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitcommevent) operation, this value is undefined.

### `dwMilliseconds` [in]

The time-out interval, in milliseconds.

If *dwMilliseconds* is zero and the operation is still in progress, the function returns immediately and the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_IO_INCOMPLETE**.

If *dwMilliseconds* is nonzero and the operation is still in progress, the function waits until the object is signaled, an I/O completion routine or APC is queued, or the interval elapses before returning. Use [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

If *dwMilliseconds* is **INFINITE**, the function returns only when the object is signaled or an I/O completion routine or APC is queued.

The *dwMilliseconds* value does not include time spent in low-power states. For example, the timeout does not continue counting down while the computer is asleep.

### `bAlertable` [in]

If this parameter is **TRUE** and the calling thread is in the waiting state, the function returns when the system queues an I/O completion routine or APC. The calling thread then runs the routine or function. Otherwise, the function does not return, and the completion routine or APC function is not executed.

A completion routine is queued when the [ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex) or [WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex) function in which it was specified has completed. The function returns and the completion routine is called only if *bAlertable* is **TRUE**, and the calling thread is the thread that initiated the read or write operation. An APC is queued when you call [QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Common error codes include the following:

* If *dwMilliseconds* is zero and the operation is still in progress, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_IO_INCOMPLETE**.
* If *dwMilliseconds* is nonzero, and an I/O completion routine or APC is queued, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **WAIT_IO_COMPLETION**.
* If *dwMilliseconds* is nonzero and the specified timeout interval elapses, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **WAIT_TIMEOUT**.

## Remarks

The **GetOverlappedResultEx** function differs from [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) in the following ways: The *dwMilliseconds* parameter can specify a timeout interval for the operation, and the *bAlertable* parameter can specify that the calling thread should perform an alertable wait.

The results reported by the
**GetOverlappedResultEx** function are those of the specified handle's last overlapped operation to which the specified
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure was provided, and for which the operation's results were pending. A pending operation is indicated when the function that started the operation returns FALSE, and the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_IO_PENDING**. When an I/O operation is pending, the function that started the operation resets the **hEvent** member of the
**OVERLAPPED** structure to the nonsignaled state. Then when the pending operation has been completed, the system sets the event object to the signaled state.

Specify a manual-reset event object in the
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. If an auto-reset event object is used, the event handle must not be specified in any other wait operation in the interval between starting the overlapped operation and the call to
**GetOverlappedResultEx**. For example, the event object is sometimes specified in one of the wait functions to wait for the operation's completion. When the wait function returns, the system sets an auto-reset event's state to nonsignaled, and a subsequent call to
**GetOverlappedResultEx** with the *dwMilliseconds* parameter set to **INFINITE** causes the function to be blocked indefinitely.

If the **hEvent** member of the
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure is **NULL**, the system uses the state of the *hFile* handle to signal when the operation has been completed. Use of file, named pipe, or communications-device handles for this purpose is discouraged. It is safer to use an event object because of the confusion that can occur when multiple simultaneous overlapped operations are performed on the same file, named pipe, or communications device. In this situation, there is no way to know which operation caused the object's state to be signaled.

## See also

[CancelIo](https://learn.microsoft.com/windows/desktop/FileIO/cancelio)

[ConnectNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe)

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[TransactNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe)

[WaitCommEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitcommevent)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)