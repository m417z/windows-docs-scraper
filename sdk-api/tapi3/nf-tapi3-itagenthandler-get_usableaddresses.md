# ITAgentHandler::get_UsableAddresses

## Description

The
**get_UsableAddresses** method creates a collection of addresses available for receiving ACD calls on this agent handler. This method is provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateUsableAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandler-enumerateusableaddresses) method.

## Parameters

### `pVariant` [out]

Pointer to **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface pointers (address objects).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface returned by **ITAgentHandler::get_UsableAddresses**. The application must call **Release** on the
**ITAddress** interface to free resources associated with it.

## See also

[EnumerateUsableAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandler-enumerateusableaddresses)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler)

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)