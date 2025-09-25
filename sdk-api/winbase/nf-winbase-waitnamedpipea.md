# WaitNamedPipeA function

## Description

Waits until either a time-out interval elapses or an instance of the specified named pipe is available for connection (that is, the pipe's server process has a pending
[ConnectNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe) operation on the pipe).

## Parameters

### `lpNamedPipeName` [in]

The name of the named pipe. The string must include the name of the computer on which the server process is executing. A period may be used for the *servername* if the pipe is local. The following pipe name format is used:

\\*servername*\pipe\*pipename*

### `nTimeOut` [in]

The number of milliseconds that the function will wait for an instance of the named pipe to be available. You can used one of the following values instead of specifying a number of milliseconds.

| Value | Meaning |
| --- | --- |
| **NMPWAIT_USE_DEFAULT_WAIT**<br><br>0x00000000 | The time-out interval is the default value specified by the server process in the [CreateNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createnamedpipea) function. |
| **NMPWAIT_WAIT_FOREVER**<br><br>0xffffffff | The function does not return until an instance of the named pipe is available. |

## Return value

If an instance of the pipe is available before the time-out interval elapses, the return value is nonzero.

If an instance of the pipe is not available before the time-out interval elapses, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If no instances of the specified named pipe exist, the
**WaitNamedPipe** function returns immediately, regardless of the time-out value.

If the time-out interval expires, the **WaitNamedPipe** function will fail with the error **ERROR_SEM_TIMEOUT**.

If the function succeeds, the process should use the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function to open a handle to the named pipe. A return value of **TRUE** indicates that there is at least one instance of the pipe available. A subsequent **CreateFile** call to the pipe can fail, because the instance was closed by the server or opened by another client.

**Windows 10, version 1709:** Pipes are only supported within an app-container; ie, from one UWP process to another UWP process that's part of the same app. Also, named pipes must use the syntax `\\.\pipe\LOCAL\` for the pipe name.

#### Examples

For an example, see
[Named Pipe Client](https://learn.microsoft.com/windows/desktop/ipc/named-pipe-client).

## See also

[CallNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-callnamedpipea)

[ConnectNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[CreateNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createnamedpipea)

[Pipe Functions](https://learn.microsoft.com/windows/desktop/ipc/pipe-functions)

[Pipes Overview](https://learn.microsoft.com/windows/desktop/ipc/pipes)