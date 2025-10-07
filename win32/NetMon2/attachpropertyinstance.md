# AttachPropertyInstance function

The **AttachPropertyInstance** function maps an existing property to a specific location in the recognized data.

## Parameters

*hFrame* \[in\]

Handle to the frame that is being parsed. Use the handle passed to the parser DLL in the *hFrame* parameter of the [**AttachProperties**](https://learn.microsoft.com/windows/win32/netmon2/attachproperties) function.

*hProperty* \[in\]

Handle to a [**PROPERTYINFO**](https://learn.microsoft.com/windows/win32/netmon2/propertyinfo) structure that defines the property. When you implement the [**Register**](https://learn.microsoft.com/windows/win32/netmon2/register-parser) export function you specify the **PROPERTYINFO** structure that defines the property.

*Length* \[in\]

Length of the data for this instance of the property.

*lpData* \[in\]

Pointer to the location in the recognized data where the property value is located. Use the pointer passed to the parser DLL in the *lpProtocol* parameter of the [**AttachProperties**](https://learn.microsoft.com/windows/win32/netmon2/attachproperties) function.

*HelpID* \[in\]

Identifier (from 0 to 2047) used to set context-sensitive Help for the property.

The identifier number is relative to the Help file associated with the protocol [*property database*](https://learn.microsoft.com/windows/win32/netmon2/p).

*IndentLevel* \[in\]

Indentation level (from 0 to 15) used to display a property hierarchically.

Network Monitor uses levels 0 through 14 to indent properties. Level 15 is a special value that allows a parser to attach a hidden property that is not visible.

*IFlags* \[in\]

A BIT field value that indicates the order of the BITs within a property. Previous parsers that set *fError* to 0 or 1, should now set *fError* to IFLAG\_ERROR. Set this parameter to one of the following values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------|
| **IFLAG\_ERROR** | Data in the frame has an error.<br> |
| **IFLAG\_SWAPPED** | At attach time, **WORD** byte is a non-Intel format.<br> |
| **IFLAG\_UNICODE** | At attach time, **STRING** is Unicode.<br> |

## Return value

If the function is successful, the return value is **TRUE**.

If the function is unsuccessful, the return value is **FALSE**.

## Remarks

The **AttachPropertyInstance** function is called during the implementation of the [**AttachProperties**](https://learn.microsoft.com/windows/win32/netmon2/attachproperties) export function. When a property is attached to the data, Network Monitor creates a [**PROPERTYINST**](https://learn.microsoft.com/windows/win32/netmon2/propertyinst) structure that defines the instance of the attached property.

During the implementation of [**AttachProperties**](https://learn.microsoft.com/windows/win32/netmon2/attachproperties), call **AttachPropertyInstance** to use the data as it exists in the capture. You can also call [**AttachPropertyInstanceEx**](https://learn.microsoft.com/windows/win32/netmon2/attachpropertyinstanceex) function to modify the property data. However, it is advised that you use the data as it exists in the capture.

| For Information on | See |
|-----------------------------------------------------------|--------------------------------------------------------------------|
| What parsers are, and how they work with Network Monitor. | [**Parsers**](https://learn.microsoft.com/windows/win32/netmon2/parsers) |
| How to call **AttachPropertyInstance**. | [Implementing AttachProperties](https://learn.microsoft.com/windows/win32/netmon2/implementing-attachproperties) |

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[**AttachProperties**](https://learn.microsoft.com/windows/win32/netmon2/attachproperties)

[**AttachPropertyInstanceEx**](https://learn.microsoft.com/windows/win32/netmon2/attachpropertyinstanceex)

[**PROPERTYINST**](https://learn.microsoft.com/windows/win32/netmon2/propertyinst)

