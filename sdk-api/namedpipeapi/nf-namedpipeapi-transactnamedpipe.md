# TransactNamedPipe function

## Description

Combines the functions that write a message to and read a message from the specified named pipe into a single operation.

## Parameters

### `hNamedPipe` [in]

A handle to the named pipe returned by the
[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea) or
[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) function.

This parameter can also be a handle to an anonymous pipe, as returned by the
[CreatePipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-createpipe) function.

### `lpInBuffer` [in]

A pointer to the buffer containing the data to be written to the pipe.

### `nInBufferSize` [in]

The size of the input buffer, in bytes.

### `lpOutBuffer` [out]

A pointer to the buffer that receives the data read from the pipe.

### `nOutBufferSize` [in]

The size of the output buffer, in bytes.

### `lpBytesRead` [out]

A pointer to the variable that receives the number of bytes read from the pipe.

If *lpOverlapped* is **NULL**, *lpBytesRead* cannot be **NULL**.

If *lpOverlapped* is not **NULL**, *lpBytesRead* can be **NULL**. If this is an overlapped read operation, you can get the number of bytes read by calling
[GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult). If *hNamedPipe* is associated with an I/O completion port, you can get the number of bytes read by calling
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus).

### `lpOverlapped` [in, out, optional]

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure. This structure is required if *hNamedPipe* was opened with FILE_FLAG_OVERLAPPED.

If *hNamedPipe* was opened with FILE_FLAG_OVERLAPPED, the *lpOverlapped* parameter must not be **NULL**. It must point to a valid [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure. If *hNamedPipe* was created with FILE_FLAG_OVERLAPPED and *lpOverlapped* is **NULL**, the function can incorrectly report that the operation is complete.

If *hNamedPipe* was opened with FILE_FLAG_OVERLAPPED and *lpOverlapped* is not **NULL**,
**TransactNamedPipe** is executed as an overlapped operation. The [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure should contain a manual-reset event object (which can be created by using the
[CreateEvent](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createeventa) function). If the operation cannot be completed immediately,
**TransactNamedPipe** returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_IO_PENDING. In this situation, the event object is set to the nonsignaled state before
**TransactNamedPipe** returns, and it is set to the signaled state when the transaction has finished. Also, you can be notified when an overlapped operation completes by using the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) or [GetQueuedCompletionStatusEx](https://learn.microsoft.com/windows/win32/FileIO/getqueuedcompletionstatusex-func) functions. In this case, you do not need to assign the manual-reset event in the **OVERLAPPED** structure, and the completion happens against *hNamedPipe* in the same way as an asynchronous read or write operation. For more information about overlapped operations, see
[Pipes](https://learn.microsoft.com/windows/win32/ipc/pipes).

If *hNamedPipe* was not opened with FILE_FLAG_OVERLAPPED,
**TransactNamedPipe** does not return until the operation is complete.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the message to be read is longer than the buffer specified by the *nOutBufferSize* parameter,
**TransactNamedPipe** returns **FALSE** and the [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns ERROR_MORE_DATA. The remainder of the message can be read by a subsequent call to [ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile), [ReadFileEx](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfileex), or
[PeekNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-peeknamedpipe).

## Remarks

**TransactNamedPipe** fails if the server did not create the pipe as a message-type pipe or if the pipe handle is not in message-read mode. For example, if a client is running on the same machine as the server and uses the \\.\pipe\*pipename* format to open the pipe, the pipe is opened in byte mode by the named pipe file system (NPFS). If the client uses the form \\*server*\pipe\*pipename*, the redirector opens the pipe in message mode. A byte mode pipe handle can be changed to message-read mode with the
[SetNamedPipeHandleState](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-setnamedpipehandlestate) function.

The function cannot be completed successfully until data is written into the buffer specified by the *lpOutBuffer* parameter. The *lpOverlapped* parameter is available to enable the calling thread to perform other tasks while the operation is executing in the background.

The maximum guaranteed size of a named pipe transaction is 64 kilobytes. In some limited cases, transactions beyond 64 kilobytes are possible, depending on OS versions participating in the transaction and dynamic network conditions. However, there is no guarantee that transactions above 64 kilobytes will succeed. Therefore it's recommended that named pipe transactions be limited to 64 kilobytes of data.

**Windows 10, version 1709:** Pipes are only supported within an app-container; ie, from one UWP process to another UWP process that's part of the same app. Also, named pipes must use the syntax `\\.\pipe\LOCAL\` for the pipe name.

#### Examples

For an example, see
[Transactions on Named Pipes](https://learn.microsoft.com/windows/win32/ipc/transactions-on-named-pipes).

## See also

[CreateEvent](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createeventa)

[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew)

[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea)

[GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)

[PeekNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-peeknamedpipe)

[Pipe Functions](https://learn.microsoft.com/windows/win32/ipc/pipe-functions)

[Pipes Overview](https://learn.microsoft.com/windows/win32/ipc/pipes)

[ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile)

[ReadFileEx](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfileex)

[SetNamedPipeHandleState](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-setnamedpipehandlestate)