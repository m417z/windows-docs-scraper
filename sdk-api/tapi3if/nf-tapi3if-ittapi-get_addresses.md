# ITTAPI::get_Addresses

## Description

The
**get_Addresses** method creates a collection of addresses that are currently available. Provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-enumerateaddresses) method.

## Parameters

### `pVariant` [out]

Pointer to a **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface pointers (address objects).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *pVariant* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |

## Remarks

TAPI calls the **Addref** method on the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface returned by **ITTAPI::get_Addesses**. The application must call **Release** on the
**ITAddress** interface to free resources associated with it.

## See also

[EnumerateAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-enumerateaddresses)

[IEnumAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumaddress)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)