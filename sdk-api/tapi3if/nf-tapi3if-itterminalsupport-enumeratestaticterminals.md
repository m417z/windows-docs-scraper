# ITTerminalSupport::EnumerateStaticTerminals

## Description

The
**EnumerateStaticTerminals** method enumerates the currently available static terminals associated with the address. This method is provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_StaticTerminals](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-get_staticterminals) method.

## Parameters

### `ppTerminalEnumerator` [out]

Pointer to an
[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal) enumerator.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppTerminalEnumerator* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal) interface returned by **ITTerminalSupport::EnumerateStaticTerminals**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**IEnumTerminal** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITTerminalSupport](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminalsupport)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[Terminal Object Interfaces](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object-interfaces)