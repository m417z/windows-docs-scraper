# ITTerminalSupport::get_DynamicTerminalClasses

## Description

The
**get_DynamicTerminalClasses** method creates a collection of currently available dynamic terminals. This method is provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateDynamicTerminalClasses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-enumeratedynamicterminalclasses) method.

## Parameters

### `pVariant` [out]

Pointer to a **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[terminal classes](https://learn.microsoft.com/windows/desktop/Tapi/terminal-class) in a string (**BSTR**) format.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |

## Remarks

An application calls this method to find out which dynamic terminal classes are supported by this address in a call to
[ITTerminalSupport::CreateTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-createterminal).

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITTerminalSupport](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminalsupport)

[Terminal Class](https://learn.microsoft.com/windows/desktop/Tapi/terminal-class)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[Terminal Object Interfaces](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object-interfaces)