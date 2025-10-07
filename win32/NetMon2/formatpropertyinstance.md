# FormatPropertyInstance function

The **FormatPropertyInstance** function formats the property instance data using the generic formatter that Network Monitor provides.

## Parameters

*lpPropertyInst* \[in, out\]

A pointer to a [PROPERTYINST](https://learn.microsoft.com/windows/win32/netmon2/propertyinst) structure that contains the instance data.

On input, the generic formatter takes the instance data from one of the **PROPERTYINST** union members and converts that data to a predefined formatted string.

On output, the generic formatter sets the **szPropertyText** member of the **PROPERTYINST** structure to a pointer to the formatted string.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is an error code from NMerr.h.

## Remarks

The parser DLL indirectly calls the **FormatPropertyInstance** function when the generic formatter is required to format data for display in the details pane of the Network Monitor UI. To call **FormatPropertyInstance** specify it in the **InstanceData** member of the [PROPERTYINFO](https://learn.microsoft.com/windows/win32/netmon2/propertyinfo) structure when you define the property.

> [!Note]
> The parser does not recognize which function is called when it must format an instance of a property. The function can be **FormatPropertyInstance** or a custom format function defined by the parser. The parser calls whatever format function is specified by the **InstanceData** member of the **PROPERTYINFO** structure for the property.

For more information and an example of how to implement [formatproperties](https://learn.microsoft.com/windows/win32/netmon2/formatproperties), see [Implementing FormatProperties](https://learn.microsoft.com/windows/win32/netmon2/implementing-formatproperties). For more information about how the generic formatter formats different types of data, see [Generic Formatter Output](https://learn.microsoft.com/windows/win32/netmon2/generic-formatter-output).

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[PROPERTYINFO](https://learn.microsoft.com/windows/win32/netmon2/propertyinfo)

[PROPERTYINST](https://learn.microsoft.com/windows/win32/netmon2/propertyinst)

