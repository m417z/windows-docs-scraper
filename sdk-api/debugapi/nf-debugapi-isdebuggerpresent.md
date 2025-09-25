# IsDebuggerPresent function

## Description

Determines whether the calling process is being debugged by a user-mode debugger.

## Return value

If the current process is running in the context of a debugger, the return value is nonzero.

If the current process is not running in the context of a debugger, the return value is zero.

## Remarks

This function allows an application to determine whether or not it is being debugged, so that it can modify its behavior. For example, an application could provide additional information using the
[OutputDebugString](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-outputdebugstringw) function if it is being debugged.

To determine whether a remote process is being debugged, use the [CheckRemoteDebuggerPresent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-checkremotedebuggerpresent) function.

## See also

[CheckRemoteDebuggerPresent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-checkremotedebuggerpresent)

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)

[OutputDebugString](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-outputdebugstringw)