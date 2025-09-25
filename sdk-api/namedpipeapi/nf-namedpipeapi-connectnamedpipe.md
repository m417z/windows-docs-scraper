# ConnectNamedPipe function

## Description

Enables a named pipe server process to wait for a client process to connect to an instance of a named pipe. A client process connects by calling either the
[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) or
[CallNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-callnamedpipea) function.

## Parameters

### `hNamedPipe` [in]

A handle to the server end of a named pipe instance. This handle is returned by the
[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea) function.

### `lpOverlapped` [in, out, optional]

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure.

If *hNamedPipe* was opened with FILE_FLAG_OVERLAPPED, the *lpOverlapped* parameter must not be **NULL**. It must point to a valid [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure. If *hNamedPipe* was opened with FILE_FLAG_OVERLAPPED and *lpOverlapped* is **NULL**, the function can incorrectly report that the connect operation is complete.

If *hNamedPipe* was created with FILE_FLAG_OVERLAPPED and *lpOverlapped* is not **NULL**, the [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure should contain a handle to a manual-reset event object (which the server can create by using the
[CreateEvent](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createeventa) function).

If *hNamedPipe* was not opened with FILE_FLAG_OVERLAPPED, the function does not return until a client is connected or an error occurs. Successful synchronous operations result in the function returning a nonzero value if a client connects after the function is called.

## Return value

If the operation is synchronous, **ConnectNamedPipe** does not return until the operation has completed. If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the operation is asynchronous, **ConnectNamedPipe** returns immediately. If the operation is still pending, the return value is zero and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_IO_PENDING. (You can use the [HasOverlappedIoCompleted](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-hasoverlappediocompleted) macro to determine when the operation has finished.) If the function fails, the return value is zero and
**GetLastError** returns a value other than ERROR_IO_PENDING or ERROR_PIPE_CONNECTED.

If a client connects before the function is called, the function returns zero and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_PIPE_CONNECTED. This can happen if a client connects in the interval between the call to
[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea) and the call to
**ConnectNamedPipe**. In this situation, there is a good connection between client and server, even though the function returns zero.

## Remarks

A named pipe server process can use
**ConnectNamedPipe** with a newly created pipe instance. It can also be used with an instance that was previously connected to another client process; in this case, the server process must first call the
[DisconnectNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-disconnectnamedpipe) function to disconnect the handle from the previous client before the handle can be reconnected to a new client. Otherwise,
**ConnectNamedPipe** returns zero, and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NO_DATA if the previous client has closed its handle or ERROR_PIPE_CONNECTED if it has not closed its handle.

The behavior of
**ConnectNamedPipe** depends on two conditions: whether the pipe handle's wait mode is set to blocking or nonblocking and whether the function is set to execute synchronously or in overlapped mode. A server initially specifies a pipe handle's wait mode in the
[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea) function, and it can be changed by using the
[SetNamedPipeHandleState](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-setnamedpipehandlestate) function.

The server process can use any of the
[wait functions](https://learn.microsoft.com/windows/win32/Sync/wait-functions) or
[SleepEx](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-sleepex)— to determine when the state of the event object is signaled, and it can then use the [HasOverlappedIoCompleted](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-hasoverlappediocompleted)
macro to determine when the
**ConnectNamedPipe** operation completes.

If the specified pipe handle is in nonblocking mode,
**ConnectNamedPipe** always returns immediately. In nonblocking mode,
**ConnectNamedPipe** returns a nonzero value the first time it is called for a pipe instance that is disconnected from a previous client. This indicates that the pipe is now available to be connected to a new client process. In all other situations when the pipe handle is in nonblocking mode,
**ConnectNamedPipe** returns zero. In these situations, [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_PIPE_LISTENING if no client is connected, ERROR_PIPE_CONNECTED if a client is connected, and ERROR_NO_DATA if a previous client has closed its pipe handle but the server has not disconnected. Note that a good connection between client and server exists only after the ERROR_PIPE_CONNECTED error is received.

**Note** Nonblocking mode is supported for compatibility with Microsoft LAN Manager version 2.0, and it should not be used to achieve asynchronous input and output (I/O) with named pipes.

**Windows 10, version 1709 and later:** Pipes cannot be used to communicate between app-containers; ie, from one UWP process to another UWP process that's not part of the same app. Also, named pipes within app-containers must use the syntax `\\.\pipe\LOCAL\` for the pipe name.

#### Examples

For an example, see
[Multithreaded Pipe Server](https://learn.microsoft.com/windows/win32/ipc/multithreaded-pipe-server).

## See also

[CallNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-callnamedpipea)

[CreateEvent](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createeventa)

[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew)

[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea)

[DisconnectNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-disconnectnamedpipe)

[GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)

[OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)

[Pipe Functions](https://learn.microsoft.com/windows/win32/ipc/pipe-functions)

[Pipes Overview](https://learn.microsoft.com/windows/win32/ipc/pipes)

[SetNamedPipeHandleState](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-setnamedpipehandlestate)

[SleepEx](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-sleepex)