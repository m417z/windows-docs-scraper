# PeekNamedPipe function

## Description

Copies data from a named or anonymous pipe into a buffer without removing it from the pipe. It also returns information about data in the pipe.

## Parameters

### `hNamedPipe` [in]

A handle to the pipe. This parameter can be a handle to a named pipe instance, as returned by the
[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea) or
[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) function, or it can be a handle to the read end of an anonymous pipe, as returned by the
[CreatePipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-createpipe) function. The handle must have GENERIC_READ access to the pipe.

### `lpBuffer` [out, optional]

A pointer to a buffer that receives data read from the pipe. This parameter can be **NULL** if no data is to be read.

### `nBufferSize` [in]

The size of the buffer specified by the *lpBuffer* parameter, in bytes. This parameter is ignored if *lpBuffer* is **NULL**.

### `lpBytesRead` [out, optional]

A pointer to a variable that receives the number of bytes read from the pipe. This parameter can be **NULL** if no data is to be read.

### `lpTotalBytesAvail` [out, optional]

A pointer to a variable that receives the total number of bytes available to be read from the pipe. This parameter can be **NULL** if no data is to be read.

### `lpBytesLeftThisMessage` [out, optional]

A pointer to a variable that receives the number of bytes remaining in this message. This parameter will be zero for byte-type named pipes or for anonymous pipes. This parameter can be **NULL** if no data is to be read.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**PeekNamedPipe** function is similar to the
[ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile) function with the following exceptions:

* The data is read in the mode specified with
  [CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea). For example, create a pipe with PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE. If you change the mode to PIPE_READMODE_BYTE with
  [SetNamedPipeHandleState](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-setnamedpipehandlestate), [ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile) will read in byte mode, but
  **PeekNamedPipe** will continue to read in message mode.
* The data read from the pipe is not removed from the pipe's buffer.
* The function can return additional information about the contents of the pipe.
* The function always returns immediately in a single-threaded application, even if there is no data in the pipe. The wait mode of a named pipe handle (blocking or nonblocking) has no effect on the function.

**Note** The **PeekNamedPipe** function can block thread execution the same way any I/O function can when called on a synchronous handle in a multi-threaded application. To avoid this condition, use a pipe handle created for [asynchronous I/O](https://learn.microsoft.com/windows/win32/FileIO/synchronous-and-asynchronous-i-o).

If the specified handle is a named pipe handle in byte-read mode, the function reads all available bytes up to the size specified in *nBufferSize*. For a named pipe handle in message-read mode, the function reads the next message in the pipe. If the message is larger than *nBufferSize*, the function returns **TRUE** after reading the specified number of bytes. In this situation, *lpBytesLeftThisMessage* will receive the number of bytes remaining in the message.

**Windows 10, version 1709:** Pipes are only supported within an app-container; ie, from one UWP process to another UWP process that's part of the same app. Also, named pipes must use the syntax `\\.\pipe\LOCAL\` for the pipe name.

## See also

[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew)

[CreateNamedPipe](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createnamedpipea)

[CreatePipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-createpipe)

[Pipe Functions](https://learn.microsoft.com/windows/win32/ipc/pipe-functions)

[Pipes Overview](https://learn.microsoft.com/windows/win32/ipc/pipes)

[ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile)

[WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile)