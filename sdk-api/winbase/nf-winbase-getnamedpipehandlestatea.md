# GetNamedPipeHandleStateA function

## Description

Retrieves information about a specified named pipe. The information returned can vary during the lifetime of an instance of the named pipe.

## Parameters

### `hNamedPipe` [in]

A handle to the named pipe for which information is wanted. The handle must have GENERIC_READ access for a read-only or read/write pipe, or it must have GENERIC_WRITE and FILE_READ_ATTRIBUTES access for a write-only pipe.

This parameter can also be a handle to an anonymous pipe, as returned by the
[CreatePipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-createpipe) function.

### `lpState` [out, optional]

A pointer to a variable that indicates the current state of the handle. This parameter can be **NULL** if this information is not needed. Either or both of the following values can be specified.

| Value | Meaning |
| --- | --- |
| **PIPE_NOWAIT**<br><br>0x00000001 | The pipe handle is in nonblocking mode. If this flag is not specified, the pipe handle is in blocking mode. |
| **PIPE_READMODE_MESSAGE**<br><br>0x00000002 | The pipe handle is in message-read mode. If this flag is not specified, the pipe handle is in byte-read mode. |

### `lpCurInstances` [out, optional]

A pointer to a variable that receives the number of current pipe instances. This parameter can be **NULL** if this information is not required.

### `lpMaxCollectionCount` [out, optional]

A pointer to a variable that receives the maximum number of bytes to be collected on the client's computer before transmission to the server. This parameter must be **NULL** if the specified pipe handle is to the server end of a named pipe or if client and server processes are on the same computer. This parameter can be **NULL** if this information is not required.

### `lpCollectDataTimeout` [out, optional]

A pointer to a variable that receives the maximum time, in milliseconds, that can pass before a remote named pipe transfers information over the network. This parameter must be **NULL** if the specified pipe handle is to the server end of a named pipe or if client and server processes are on the same computer. This parameter can be **NULL** if this information is not required.

### `lpUserName` [out, optional]

A pointer to a buffer that receives the user name string associated with the client application. The server can only retrieve this information if the client opened the pipe with SECURITY_IMPERSONATION access.

This parameter must be **NULL** if the specified pipe handle is to the client end of a named pipe. This parameter can be **NULL** if this information is not required.

### `nMaxUserNameSize` [in]

The size of the buffer specified by the *lpUserName* parameter, in **TCHARs**. This parameter is ignored if *lpUserName* is **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**GetNamedPipeHandleState** function returns successfully even if all of the pointers passed to it are **NULL**.

To set the pipe handle state, use the
[SetNamedPipeHandleState](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-setnamedpipehandlestate) function.

**Windows 10, version 1709:** Pipes are only supported within an app-container; ie, from one UWP process to another UWP process that's part of the same app. Also, named pipes must use the syntax `\\.\pipe\LOCAL\` for the pipe name.

## See also

[Pipe Functions](https://learn.microsoft.com/windows/desktop/ipc/pipe-functions)

[Pipes Overview](https://learn.microsoft.com/windows/desktop/ipc/pipes)

[SetNamedPipeHandleState](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-setnamedpipehandlestate)