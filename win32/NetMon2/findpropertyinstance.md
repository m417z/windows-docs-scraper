# FindPropertyInstance function

The **FindPropertyInstance** function finds the first instance of the property specified by the *hProperty* parameter.

## Parameters

*hFrame* \[in\]

Handle to the frame. The frame handle can be retrieved by a call to the [GetFrame](https://learn.microsoft.com/windows/win32/netmon2/getframe) function.

*hProperty* \[in\]

Handle to the property you want to find. The property handle can be retrieved by a call to the [GetProperty](https://learn.microsoft.com/windows/win32/netmon2/getproperty) function.

## Return value

If the function is successful (that is, if the property is found), the return value is a pointer to the first instance of the property.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

To retrieve the next instance of the property, call [FindPropertyInstanceRestart](https://learn.microsoft.com/windows/win32/netmon2/findpropertyinstancerestart).

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p)can call the **FindPropertyInstance** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[FindPropertyInstanceRestart](https://learn.microsoft.com/windows/win32/netmon2/findpropertyinstancerestart)

