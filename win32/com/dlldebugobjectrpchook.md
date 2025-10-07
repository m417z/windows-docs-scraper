# DllDebugObjectRPCHook function

Exported by COM DLLs to enable remote debugging.

## Parameters

*fTrace*

If **TRUE**, remote debugging is enabled. If **FALSE**, remote debugging is not enabled.

*lpOrpcInitArgs*

A pointer to an [**ORPC\_INIT\_ARGS**](https://learn.microsoft.com/windows/win32/com/orpc-init-args) structure.

## Return value

**TRUE** if successful, **FALSE** otherwise

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | N/A |
| Library<br> | Ole32.lib |
| DLL<br> | Ole32.dll |

## See also

[**ORPC\_DBG\_ALL**](https://learn.microsoft.com/windows/win32/com/orpc-dbg-all)

[**ORPC\_DBG\_BUFFER**](https://learn.microsoft.com/windows/win32/com/orpc-dbg-buffer)

[**ORPC\_INIT\_ARGS**](https://learn.microsoft.com/windows/win32/com/orpc-init-args)

[**IOrpcDebugNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify)

