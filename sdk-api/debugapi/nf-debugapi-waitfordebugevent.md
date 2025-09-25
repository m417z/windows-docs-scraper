# WaitForDebugEvent function

## Description

Waits for a debugging event to occur in a process being debugged.

**Important** In the past, the operating system did not output Unicode strings via **OutputDebugStringW** and instead only output ASCII strings. To force **OutputDebugStringW** to correctly output Unicode strings, debuggers are required to call [WaitForDebugEventEx](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-waitfordebugeventex) to opt into the new behavior. On calling **WaitForDebugEventEx**, the operating system will know that the debugger supports Unicode and is specifically opting into receiving Unicode strings.

## Parameters

### `lpDebugEvent` [out]

A pointer to a
[DEBUG_EVENT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-debug_event) structure that receives information about the debugging event.

### `dwMilliseconds` [in]

The number of milliseconds to wait for a debugging event. If this parameter is zero, the function tests for a debugging event and returns immediately. If the parameter is INFINITE, the function does not return until a debugging event has occurred.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Only the thread that created the process being debugged can call
**WaitForDebugEvent**.

When a CREATE_PROCESS_DEBUG_EVENT occurs, the debugger application receives a handle to the image file of the process being debugged, a handle to the process being debugged, and a handle to the initial thread of the process being debugged in the
[DEBUG_EVENT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-debug_event) structure. The members these handles are returned in are **u.CreateProcessInfo.hFile** (image file), **u.CreateProcessInfo.hProcess** (process), and **u.CreateProcessInfo.hThread** (initial thread). If the system previously reported an EXIT_PROCESS_DEBUG_EVENT debugging event, the system closes the handles to the process and thread when the debugger calls the
[ContinueDebugEvent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-continuedebugevent) function. The debugger should close the handle to the image file by calling the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

Similarly, when a CREATE_THREAD_DEBUG_EVENT occurs, the debugger application receives a handle to the thread whose creation caused the debugging event in the **u.CreateThread.hThread** member of the
[DEBUG_EVENT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-debug_event) structure. If the system previously reported an EXIT_THREAD_DEBUG_EVENT debugging event, the system closes the handles to the thread when the debugger calls the
[ContinueDebugEvent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-continuedebugevent) function.

When a LOAD_DLL_DEBUG_EVENT occurs, the debugger application receives a handle to the loaded DLL in the **u.LoadDll.hFile** member of the
[DEBUG_EVENT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-debug_event) structure. This handle should be closed by the debugger application by calling the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

**Warning** Do not queue an
[asynchronous procedure call](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls) (APC) to a thread that calls
**WaitForDebugEvent**.

#### Examples

For an example, see
[Writing the Debugger's Main Loop](https://learn.microsoft.com/windows/desktop/Debug/writing-the-debugger-s-main-loop).

## See also

[ContinueDebugEvent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-continuedebugevent)

[DEBUG_EVENT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-debug_event)

[DebugActiveProcess](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugactiveprocess)

[DebugBreak](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugbreak)

[Debugging Events](https://learn.microsoft.com/windows/desktop/Debug/debugging-events)

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)

[OutputDebugString](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-outputdebugstringw)