# ITAgentHandler::EnumerateUsableAddresses

## Description

The
**EnumerateUsableAddresses** method enumerates addresses available for receiving ACD calls on this agent handler. This method is provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_UsableAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandler-get_usableaddresses) method.

## Parameters

### `ppEnumAddress` [out]

Pointer to
[IEnumAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumaddress) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppEnumAddress* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumaddress) interface returned by **ITAgentHandler::EnumerateUsableAddresses**. The application must call **Release** on the
**IEnumAddress** interface to free resources associated with it.

## See also

[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler)