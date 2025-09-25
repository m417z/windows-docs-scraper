# DebugBreak function

## Description

Causes a breakpoint exception to occur in the current process. This allows the calling thread to signal the debugger to handle the exception.

To cause a breakpoint exception in another process, use the
[DebugBreakProcess](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-debugbreakprocess) function.

## Remarks

If the process is not being debugged, the function uses the search logic of a standard exception handler. In most cases, this causes the calling process to terminate because of an unhandled breakpoint exception.

#### Examples

For an example, see
[Using an Exception Handler](https://learn.microsoft.com/windows/desktop/Debug/using-an-exception-handler).

## See also

[Communicating with the Debugger](https://learn.microsoft.com/windows/desktop/Debug/communicating-with-the-debugger)

[DebugActiveProcess](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugactiveprocess)

[DebugBreakProcess](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-debugbreakprocess)

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)