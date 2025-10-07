# FindPropertyInstanceRestart function

The **FindPropertyInstanceRestart** function finds the next instance of the property specified by the *hProperty* parameter.

## Parameters

*hFrame* \[in\]

A handle to the frame. The frame handle can be retrieved by a call to the [GetFrame](https://learn.microsoft.com/windows/win32/netmon2/getframe) function.

*hProperty* \[in\]

A handle to the property to find. The property handle can be retrieved by a call to the [GetProperty](https://learn.microsoft.com/windows/win32/netmon2/getproperty) function.

*lpRestartKey* \[in\]

A pointer to the property instance used as the starting point of the search. If the *lpRestartKey* parameter is set to **NULL**, the search begins at beginning of the frame, or the end of the frame, depending on the value of the *DirForward* parameter.

If *lpRestartKey* points to **NULL**, the search begins at the beginning of the frame if *DirForward* is **TRUE** or the at end of the frame if the parameter is **FALSE**.

*DirForward* \[in\]

An indicator of the search direction. If the value is **TRUE**, the search moves from the current location to the end of the frame. If the value is **FALSE**, the search moves from the current location to the beginning of the frame.

## Return value

If the function is successful, the return value is the next valid **LPPROPERTYINST**.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **FindPropertyInstanceRestart** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[GetFrame](https://learn.microsoft.com/windows/win32/netmon2/getframe)

[GetProperty](https://learn.microsoft.com/windows/win32/netmon2/getproperty)

