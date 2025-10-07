# GetProperty function

The **GetProperty** function returns a handle to a given property.

## Parameters

*hProtocol* \[in\]

Handle to the protocol.

*PropertyName* \[in\]

Name of the property (for example, **Checksum**).

## Return value

If the function is successful, the return value is the handle to the property.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

The **GetProperty** function can be used to obtain the property handle needed to locate instances of the property. The functions used to locate property instances are [FindPropertyInstance](https://learn.microsoft.com/windows/win32/netmon2/findpropertyinstance) (which locates the first instance) and [FindPropertyInstanceRestart](https://learn.microsoft.com/windows/win32/netmon2/findpropertyinstancerestart) (which locates the next instance).

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetProperty** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[FindPropertyInstance](https://learn.microsoft.com/windows/win32/netmon2/findpropertyinstance)

[FindPropertyInstanceRestart](https://learn.microsoft.com/windows/win32/netmon2/findpropertyinstancerestart)

