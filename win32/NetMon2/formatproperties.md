# FormatProperties callback function

The **FormatProperties** export function formats the data that is displayed in the details pane of the Network Monitor UI. If you want to display data in the details pane, you must implement the **FormatProperties** export function in all parser DLLs.

## Parameters

*hFrame* \[in\]

Handle to the frame that is being parsed.

*lpFrame* \[in\]

Pointer to the first byte of a frame.

*lpProtocol* \[in\]

Pointer to the beginning of the protocol data in a frame.

*nPropertyInsts* \[in\]

Number of [PROPERTYINST](https://learn.microsoft.com/windows/win32/netmon2/propertyinst) structures provided by *lpPropInst*.

*lpPropInst* \[in\]

Pointer to an array of [PROPERTYINST](https://learn.microsoft.com/windows/win32/netmon2/propertyinst) structures.

## Return value

If the function is successful, the return value is **TRUE**.

If the function is unsuccessful, the return value is **FALSE**.

## Remarks

Network Monitor calls the **FormatProperties** function to display data in the details pane of the Network Monitor UI. Typically, **FormatProperties** is called to format the summary line for a protocol, and then to format all the property instances of the protocol within a frame. However, Network Monitor does not guarantee the number of times it calls **FormatProperties** for a specific parser.

During the implementation of the **FormatProperties** function, the parser indirectly calls the [FormatPropertyInstance](https://learn.microsoft.com/windows/win32/netmon2/formatpropertyinstance) function to use the generic formatter that Network Monitor provides, or it can call a custom formatter procedure that is defined by the parser. One of the formatters must be called for each [PROPERTYINST](https://learn.microsoft.com/windows/win32/netmon2/propertyinst) structure passed to the parser DLL in the *lpPropInst* parameter.

| For Information on | See |
|-------------------------------------------------------------|--------------------------------------------------------------------|
| What parsers are, and how they work with Network Monitor. | [Parsers](https://learn.microsoft.com/windows/win32/netmon2/parsers) |
| Which entry points are included in the parser DLL. | [Parser DLL Architecture](https://learn.microsoft.com/windows/win32/netmon2/parser-dll-architecture) |
| How to implement **FormatProperties** includes an example. | [Implementing FormatProperties](https://learn.microsoft.com/windows/win32/netmon2/implementing-formatproperties) |
| How the generic formatter formats different types of data. | [Generic Formatter Output](https://learn.microsoft.com/windows/win32/netmon2/generic-formatter-output) |

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[FormatPropertyInstance](https://learn.microsoft.com/windows/win32/netmon2/formatpropertyinstance)

[PROPERTYINFO](https://learn.microsoft.com/windows/win32/netmon2/propertyinfo)

[PROPERTYINST](https://learn.microsoft.com/windows/win32/netmon2/propertyinst)

