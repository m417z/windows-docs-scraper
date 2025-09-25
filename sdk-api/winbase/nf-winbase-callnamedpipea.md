# CallNamedPipeA function

## Description

Connects to a message-type pipe (and waits if an instance of the pipe is not available), writes to and reads from the pipe, and then closes the pipe.

## Parameters

### `lpNamedPipeName` [in]

The pipe name.

### `lpInBuffer` [in]

The data to be written to the pipe.

### `nInBufferSize` [in]

The size of the write buffer, in bytes.

### `lpOutBuffer` [out]

A pointer to the buffer that receives the data read from the pipe.

### `nOutBufferSize` [in]

The size of the read buffer, in bytes.

### `lpBytesRead` [out]

A pointer to a variable that receives the number of bytes read from the pipe.

### `nTimeOut` [in]

The number of milliseconds to wait for the named pipe to be available. In addition to numeric values, the following special values can be specified.

| Value | Meaning |
| --- | --- |
| **NMPWAIT_NOWAIT**<br><br>0x00000001 | Does not wait for the named pipe. If the named pipe is not available, the function returns an error. |
| **NMPWAIT_WAIT_FOREVER**<br><br>0xffffffff | Waits indefinitely. |
| **NMPWAIT_USE_DEFAULT_WAIT**<br><br>0x00000000 | Uses the default time-out specified in a call to the [CreateNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createnamedpipea) function. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the message written to the pipe by the server process is longer than *nOutBufferSize*,
**CallNamedPipe** returns **FALSE**, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_MORE_DATA. The remainder of the message is discarded, because
**CallNamedPipe** closes the handle to the pipe before returning.

## Remarks

Calling **CallNamedPipe** is equivalent to calling the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) (or [WaitNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitnamedpipea), if **CreateFile** cannot open the pipe immediately), [TransactNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe), and [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) functions. **CreateFile** is called with an access flag of GENERIC_READ | GENERIC_WRITE, and an inherit handle flag of **FALSE**.

**CallNamedPipe** fails if the pipe is a byte-type pipe.

**Windows 10, version 1709:** Pipes are only supported within an app-container; ie, from one UWP process to another UWP process that's part of the same app. Also, named pipes must use the syntax `\\.\pipe\LOCAL\` for the pipe name.

#### Examples

For an example, see
[Transactions on Named Pipes](https://learn.microsoft.com/windows/desktop/ipc/transactions-on-named-pipes).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[CreateNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createnamedpipea)

[Pipe Functions](https://learn.microsoft.com/windows/desktop/ipc/pipe-functions)

[Pipes Overview](https://learn.microsoft.com/windows/desktop/ipc/pipes)

[TransactNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe)

[WaitNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitnamedpipea)