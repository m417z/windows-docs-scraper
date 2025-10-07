# AttachPropertyInstanceEx function

The **AttachPropertyInstanceEx** function maps an existing property to a specific location in the recognized data, and modifies the value of the property data.

## Parameters

*hFrame* \[in\]

Handle to the frame that is being parsed. Use the handle passed to the parser DLL in the *hFrame* parameter of the [**AttachProperties**](https://learn.microsoft.com/windows/win32/netmon2/attachproperties) function.

*hProperty* \[in\]

Handle to a [**PROPERTYINFO**](https://learn.microsoft.com/windows/win32/netmon2/propertyinfo) structure that defines the property. When you implement the [**Register**](https://learn.microsoft.com/windows/win32/netmon2/register-parser) export function you specify the **PROPERTYINFO** structure that defines the property.

*Length* \[in\]

Length of the data for this instance of the property.

*lpData* \[in\]

Pointer to the location in the recognized data where the property value is located. Use the pointer passed to the parser DLL in the *lpProtocol* parameter of the [**AttachProperties**](https://learn.microsoft.com/windows/win32/netmon2/attachproperties) function.

*LengthEx* \[in\]

Length of the extended data length in bytes.

*lpDataEx* \[in\]

Pointer to the extended data, which is typically a stack variable that contains the extend data.

*HelpID* \[in\]

Identifier (from 0 to 2047) used to set context-sensitive Help for a property.

The *HelpID* number is relative to the Help file associated with the protocol [*property database*](https://learn.microsoft.com/windows/win32/netmon2/p).

*IndentLevel* \[in\]

Indentation level (from 0 to 15) used to display a property hierarchically.

Network Monitor uses levels 0 through 9. Level 15 is a special value that allows the parser to attach a hidden property that is not visible.

*IFlags* \[in\]

A BIT field value that indicates the order of the BITs within a property. Previous parsers that set *fError* to 0 or 1, should now set *fError* to IFLAG\_ERROR. Set this parameter to one of the following values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------|
|

**IFLAG\_ERROR**

| Data in the frame has an error.<br> |
|

**IFLAG\_SWAPPED**

| At attach time, **WORD** byte is a non-Intel format.<br> |
|

**IFLAG\_UNICODE**

| At attach time, **STRING** is Unicode.<br> |

## Return value

If the function is successful, the return value is **TRUE**.

If the function is unsuccessful, the return value is **FALSE**.

## Remarks

The **AttachPropertyInstanceEx** function is called during the implementation of the [**AttachProperties**](https://learn.microsoft.com/windows/win32/netmon2/attachproperties) export function. When a property is attached to the data using AttachPropertyInstanceEx, Network Monitor creates a [**PROPERTYINST**](https://learn.microsoft.com/windows/win32/netmon2/propertyinst) structure that defines the instance of the attached property and a [**PROPERTYINSTEX**](https://learn.microsoft.com/windows/win32/netmon2/propertyinstex) structure that defines the extended data.

If **AttachPropertyInstanceEx** is called and no extended data is provided, the *lpDataEx* parameter is **NULL** or the *LengthEx* parameter is 0, the **AttachPropertyInstanceEx** call is functionally equivalent to an [**AttachPropertyInstance**](https://learn.microsoft.com/windows/win32/netmon2/attachpropertyinstance) call.

During the implementation of [**AttachProperties**](https://learn.microsoft.com/windows/win32/netmon2/attachproperties), call [**AttachPropertyInstance**](https://learn.microsoft.com/windows/win32/netmon2/attachpropertyinstance) to use the data as it exists in the capture. You can also call **AttachPropertyInstanceEx** function to modify the property data. However, it is advised that you use the data as it exists in the capture.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

