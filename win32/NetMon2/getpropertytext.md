# GetPropertyText function

The **GetPropertyText** function returns a pointer to the property text.

## Parameters

*hFrame* \[in\]

Handle to the frame.

*lpPI* \[in\]

Pointer to a property instance.

*szBuffer* \[in\]

Pointer to the property text string.

*BufferSize* \[in\]

Size of the text string buffer.

## Return value

If the function is successful, the return value is a pointer to the property text.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetPropertyText** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

