# GetPropertyInfo function

The **GetPropertyInfo** function returns a pointer to the property information of a given protocol.

## Parameters

*hProperty* \[in\]

Handle to a property.

## Return value

If the function is successful, the return value is a pointer to the property.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetPropertyInfo** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

