# HasOverlappedIoCompleted macro

## Description

Provides a high performance test operation that can be used to poll for the completion of an outstanding I/O operation.

## Parameters

### `lpOverlapped`

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that was specified when the overlapped I/O operation was started.

## Remarks

Do not call this macro unless the call to
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_IO_PENDING**, indicating that the overlapped I/O has started.

To cancel all pending asynchronous I/O operations, use the
[CancelIo](https://learn.microsoft.com/windows/desktop/FileIO/cancelio) function. The **CancelIo** function only cancels operations issued by the calling thread for the specified file handle. I/O operations that are canceled complete with the error **ERROR_OPERATION_ABORTED**.

To get more details about a completed I/O operation, call the
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

## See also

[CancelIo](https://learn.microsoft.com/windows/desktop/FileIO/cancelio)

[ConnectNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[TransactNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe)

[WaitCommEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitcommevent)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)