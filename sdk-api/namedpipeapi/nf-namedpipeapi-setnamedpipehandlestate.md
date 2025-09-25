# SetNamedPipeHandleState function

## Description

Sets the read mode and the blocking mode of the specified named pipe. If the specified handle is to the client end of a named pipe and if the named pipe server process is on a remote computer, the function can also be used to control local buffering.

## Parameters

### `hNamedPipe` [in]

 A handle to the named pipe instance. This parameter can be a handle to the server end of the pipe, as returned by the
[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea) function, or to the client end of the pipe, as returned by the
[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) function. The handle must have GENERIC_WRITE access to the named pipe for a write-only or read/write pipe, or it must have GENERIC_READ and FILE_WRITE_ATTRIBUTES access for a read-only pipe.

This parameter can also be a handle to an anonymous pipe, as returned by the
[CreatePipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-createpipe) function.

### `lpMode` [in, optional]

The new pipe mode. The mode is a combination of a read-mode flag and a wait-mode flag. This parameter can be **NULL** if the mode is not being set. Specify one of the following modes.

| Mode | Meaning |
| --- | --- |
| **PIPE_READMODE_BYTE**<br><br>0x00000000 | Data is read from the pipe as a stream of bytes. This mode is the default if no read-mode flag is specified. |
| **PIPE_READMODE_MESSAGE**<br><br>0x00000002 | Data is read from the pipe as a stream of messages. The function fails if this flag is specified for a byte-type pipe. |

One of the following wait modes can be specified.

| Mode | Meaning |
| --- | --- |
| **PIPE_WAIT**<br><br>0x00000000 | Blocking mode is enabled. This mode is the default if no wait-mode flag is specified. When a blocking mode pipe handle is specified in the [ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile), [WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile), or [ConnectNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe) function, operations are not finished until there is data to read, all data is written, or a client is connected. Use of this mode can mean waiting indefinitely in some situations for a client process to perform an action. |
| **PIPE_NOWAIT**<br><br>0x00000001 | Nonblocking mode is enabled. In this mode, [ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile), [WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile), and [ConnectNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe) always return immediately. Note that nonblocking mode is supported for compatibility with Microsoft LAN Manager version 2.0 and should not be used to achieve asynchronous input and output (I/O) with named pipes. |

### `lpMaxCollectionCount` [in, optional]

The maximum number of bytes collected on the client computer before transmission to the server. This parameter must be **NULL** if the specified pipe handle is to the server end of a named pipe or if client and server processes are on the same machine. This parameter is ignored if the client process specifies the FILE_FLAG_WRITE_THROUGH flag in the [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) function when the handle was created. This parameter can be **NULL** if the collection count is not being set.

### `lpCollectDataTimeout` [in, optional]

The maximum time, in milliseconds, that can pass before a remote named pipe transfers information over the network. This parameter must be **NULL** if the specified pipe handle is to the server end of a named pipe or if client and server processes are on the same computer. This parameter is ignored if the client process specified the FILE_FLAG_WRITE_THROUGH flag in the
[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) function when the handle was created. This parameter can be **NULL** if the collection count is not being set.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Windows 10, version 1709:** Pipes are only supported within an app-container; ie, from one UWP process to another UWP process that's part of the same app. Also, named pipes must use the syntax `\\.\pipe\LOCAL\` for the pipe name.

#### Examples

For an example, see
[Named Pipe Client](https://learn.microsoft.com/windows/win32/ipc/named-pipe-client).

## See also

[ConnectNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe)

[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew)

[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea)

[GetNamedPipeHandleState](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getnamedpipehandlestatea)

[Pipe Functions](https://learn.microsoft.com/windows/win32/ipc/pipe-functions)

[Pipes Overview](https://learn.microsoft.com/windows/win32/ipc/pipes)

[ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile)

[WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile)