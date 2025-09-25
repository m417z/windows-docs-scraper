# GetNamedPipeClientComputerNameA function

## Description

Retrieves the client computer name for the specified named pipe.

## Parameters

### `Pipe` [in]

A handle to an instance of a named pipe. This handle must be created by the
[CreateNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createnamedpipea) function.

### `ClientComputerName` [out]

The computer name.

### `ClientComputerNameLength` [in]

The size of the *ClientComputerName* buffer, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

**Windows 10, version 1709:** Pipes are only supported within an app-container; ie, from one UWP process to another UWP process that's part of the same app. Also, named pipes must use the syntax `\\.\pipe\LOCAL\` for the pipe name.

## See also

[CreateNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createnamedpipea)

[Pipe Functions](https://learn.microsoft.com/windows/desktop/ipc/pipe-functions)

[Pipes Overview](https://learn.microsoft.com/windows/desktop/ipc/pipes)