# WTSTerminateProcess function

## Description

Terminates the specified process on the specified Remote Desktop Session Host (RD Session Host) server.

## Parameters

### `hServer` [in]

Handle to an RD Session Host server. Specify a handle opened by the
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) function, or specify WTS_CURRENT_SERVER_HANDLE to indicate the RD Session Host server on which your application is running.

### `ProcessId` [in]

Specifies the process identifier of the process to terminate.

### `ExitCode` [in]

Specifies the exit code for the terminated process.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera)