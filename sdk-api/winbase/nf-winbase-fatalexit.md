# FatalExit function

## Description

Transfers execution control to the debugger. The behavior of the debugger thereafter is specific to the type of debugger used.

## Parameters

### `ExitCode` [in]

The error code associated with the exit.

## Return value

This function does not return a value.

## Remarks

An application should only use
**FatalExit** for debugging purposes. It should not call the function in a retail version of the application because doing so will terminate the application.

## See also

[Communicating with the Debugger](https://learn.microsoft.com/windows/desktop/Debug/communicating-with-the-debugger)

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)

[FatalAppExit](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-fatalexit)