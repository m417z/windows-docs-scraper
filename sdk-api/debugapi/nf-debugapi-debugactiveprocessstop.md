# DebugActiveProcessStop function

## Description

Stops the debugger from debugging the specified process.

## Parameters

### `dwProcessId` [in]

The identifier of the process to stop debugging.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[DebugActiveProcess](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugactiveprocess)

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)

[Debugging a Running Process](https://learn.microsoft.com/windows/desktop/Debug/debugging-a-running-process)

[Process Functions for Debugging](https://learn.microsoft.com/windows/desktop/Debug/process-functions-for-debugging)