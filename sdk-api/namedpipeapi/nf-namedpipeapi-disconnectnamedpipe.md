# DisconnectNamedPipe function

## Description

Disconnects the server end of a named pipe instance from a client process.

## Parameters

### `hNamedPipe` [in]

A handle to an instance of a named pipe. This handle must be created by the
[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the client end of the named pipe is open, the
**DisconnectNamedPipe** function forces that end of the named pipe closed. The client receives an error the next time it attempts to access the pipe. A client that is forced off a pipe by
**DisconnectNamedPipe** must still use the [CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) function to close its end of the pipe.

The pipe exists as long as a server or client process has an open handle to the pipe.

When the server process disconnects a pipe instance, any unread data in the pipe is discarded. Before disconnecting, the server can make sure data is not lost by calling the [FlushFileBuffers](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-flushfilebuffers) function, which does not return until the client process has read all the data.

The server process must call
**DisconnectNamedPipe** to disconnect a pipe handle from its previous client before the handle can be connected to another client by using the
[ConnectNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe) function.

**Windows 10, version 1709:** Pipes are only supported within an app-container; ie, from one UWP process to another UWP process that's part of the same app. Also, named pipes must use the syntax `\\.\pipe\LOCAL\` for the pipe name.

#### Examples

For an example, see
[Multithreaded Pipe Server](https://learn.microsoft.com/windows/win32/ipc/multithreaded-pipe-server).

## See also

[CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle)

[ConnectNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe)

[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea)

[FlushFileBuffers](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-flushfilebuffers)

[Pipe Functions](https://learn.microsoft.com/windows/win32/ipc/pipe-functions)

[Pipes Overview](https://learn.microsoft.com/windows/win32/ipc/pipes)