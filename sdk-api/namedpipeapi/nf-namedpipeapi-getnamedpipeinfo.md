# GetNamedPipeInfo function

## Description

Retrieves information about the specified named pipe.

## Parameters

### `hNamedPipe` [in]

A handle to the named pipe instance. The handle must have GENERIC_READ access to the named pipe for a read-only or read/write pipe, or it must have GENERIC_WRITE and FILE_READ_ATTRIBUTES access for a write-only pipe.

This parameter can also be a handle to an anonymous pipe, as returned by the
[CreatePipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-createpipe) function.

### `lpFlags` [out, optional]

A pointer to a variable that receives the type of the named pipe. This parameter can be **NULL** if this information is not required. Otherwise, this parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **PIPE_CLIENT_END**<br><br>0x00000000 | The handle refers to the client end of a named pipe instance. This is the default. |
| **PIPE_SERVER_END**<br><br>0x00000001 | The handle refers to the server end of a named pipe instance. If this value is not specified, the handle refers to the client end of a named pipe instance. |
| **PIPE_TYPE_BYTE**<br><br>0x00000000 | The named pipe is a byte pipe. This is the default. |
| **PIPE_TYPE_MESSAGE**<br><br>0x00000004 | The named pipe is a message pipe. If this value is not specified, the pipe is a byte pipe. |

### `lpOutBufferSize` [out, optional]

A pointer to a variable that receives the size of the buffer for outgoing data, in bytes. If the buffer size is zero, the buffer is allocated as needed. This parameter can be **NULL** if this information is not required.

### `lpInBufferSize` [out, optional]

A pointer to a variable that receives the size of the buffer for incoming data, in bytes. If the buffer size is zero, the buffer is allocated as needed. This parameter can be **NULL** if this information is not required.

### `lpMaxInstances` [out, optional]

A pointer to a variable that receives the maximum number of pipe instances that can be created. If the variable is set to PIPE_UNLIMITED_INSTANCES (255), the number of pipe instances that can be created is limited only by the availability of system resources. This parameter can be **NULL** if this information is not required.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Windows 10, version 1709:** Pipes are only supported within an app-container; ie, from one UWP process to another UWP process that's part of the same app. Also, named pipes must use the syntax "\\\\.\\pipe\\LOCAL\\" for the pipe name.

## See also

[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea)

[GetNamedPipeHandleState](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getnamedpipehandlestatea)

[Pipe Functions](https://learn.microsoft.com/windows/win32/ipc/pipe-functions)

[Pipes Overview](https://learn.microsoft.com/windows/win32/ipc/pipes)