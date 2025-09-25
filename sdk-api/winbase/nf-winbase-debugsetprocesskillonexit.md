# DebugSetProcessKillOnExit function

## Description

Sets the action to be performed when the calling thread exits.

## Parameters

### `KillOnExit` [in]

If this parameter is **TRUE**, the thread terminates all attached processes on exit (note that this is the default). Otherwise, the thread detaches from all processes being debugged on exit.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The calling thread must have established at least one debugging connection using the [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) or [DebugActiveProcess](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugactiveprocess) function before calling this function. **DebugSetProcessKillOnExit** affects all current and future debuggees connected to the calling thread. A thread can call this function multiple times to change the action as needed.

## See also

[DebugActiveProcessStop](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugactiveprocessstop)

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)