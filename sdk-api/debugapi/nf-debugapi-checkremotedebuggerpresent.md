# CheckRemoteDebuggerPresent function

## Description

Determines whether the specified process is being debugged.

## Parameters

### `hProcess` [in]

A handle to the process.

### `pbDebuggerPresent` [in, out]

A pointer to a variable that the function sets to **TRUE** if the specified process is being debugged, or **FALSE** otherwise.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The "remote" in **CheckRemoteDebuggerPresent** does not imply that the debugger necessarily resides on a different computer; instead, it indicates that the debugger resides in a separate and parallel process. Use the [IsDebuggerPresent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-isdebuggerpresent) function to detect whether the calling process is running under the debugger.

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0501 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)

[IsDebuggerPresent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-isdebuggerpresent)