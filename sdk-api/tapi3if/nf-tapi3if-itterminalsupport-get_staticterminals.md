# ITTerminalSupport::get_StaticTerminals

## Description

The
**get_StaticTerminals** method creates a collection of currently available static terminals. This method is provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateStaticTerminals](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-enumeratestaticterminals) method.

## Parameters

### `pVariant` [out]

Pointer to a **VARIANT**, which TAPI will fill in with an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface pointers.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface returned by **ITTerminalSupport::get_StaticTerminals**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**ITTerminal** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)

[ITTerminalSupport](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminalsupport)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[Terminal Object Interfaces](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object-interfaces)