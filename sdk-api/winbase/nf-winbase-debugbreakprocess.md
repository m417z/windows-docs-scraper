# DebugBreakProcess function

## Description

Causes a breakpoint exception to occur in the specified process. This allows the calling thread to signal the debugger to handle the exception.

## Parameters

### `Process` [in]

A handle to the process.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the process is not being debugged, the function uses the search logic of a standard exception handler. In most cases, this causes the process to terminate because of an unhandled breakpoint exception.

## See also

[Communicating with the Debugger](https://learn.microsoft.com/windows/desktop/Debug/communicating-with-the-debugger)

[DebugBreak](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugbreak)

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)