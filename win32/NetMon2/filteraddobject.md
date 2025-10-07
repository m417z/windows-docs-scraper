# FilterAddObject function

The **FilterAddObject** function adds a single object to a [*display filter*](https://learn.microsoft.com/windows/win32/netmon2/d).

## Parameters

*hFilter* \[in\]

Handle to the display filter.

*lpFilterObject* \[out\]

Pointer to a [FILTEROBJECT](https://learn.microsoft.com/windows/win32/netmon2/filterobject) structure that defines the object to be added to the filter. Each object can be an operator, value, or property.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is an error code.

| Return code | Description |
|----------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------|
| **NMERR\_INVALID\_PARAMETER** | The *hFilter* parameter has an invalid value.<br> |
| **NMERR\_OUT\_OF\_MEMORY** | Network Monitor does not have enough memory to create the object.<br> |

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **FilterAddObject** function.

The **FilterAddObject** function is called each time a filter object is added to the display filter. The display filter is a postfix stack of objects that can be an operator, value, or property.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[FILTEROBJECT](https://learn.microsoft.com/windows/win32/netmon2/filterobject)

