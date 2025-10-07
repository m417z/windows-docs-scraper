# ORPC\_INIT\_ARGS structure

The **ORPC\_INIT\_ARGS** structure contains information used to initialize remote debugging using the [**IOrpcDebugNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify) interface.

## Members

**lpIntfOrpcDebug**

A pointer to the [**IOrpcDebugNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify) interface for use by in-process debuggers. If the debugger is not in-process or is a Macintosh system, this field must be **NULL**.

**pvPSN**

A pointer to the Macintosh process serial number of the debuggee's process. If the debuggee is not a Macintosh system, this field must be **NULL**.

**dwReserved1**

Reserved. Must be 0.

**dwReserved2**

Reserved. Must be 0.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | N/A |

## See also

[**ORPC\_DBG\_ALL**](https://learn.microsoft.com/windows/win32/com/orpc-dbg-all)

[**ORPC\_DBG\_BUFFER**](https://learn.microsoft.com/windows/win32/com/orpc-dbg-buffer)

[**DllDebugObjectRPCHook**](https://learn.microsoft.com/windows/win32/com/dlldebugobjectrpchook)

[**IOrpcDebugNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify)

