# ITAddress::get_DialableAddress

## Description

The
**get_DialableAddress** method gets the **BSTR** which can be used to connect to this address. The **BSTR** corresponds to the destination address string that another application would use to connect to this address, such as a phone number or an e-mail name.

## Parameters

### `pDialableAddress` [out]

Pointer to **BSTR** containing the dialable address string. This will match the *pDestAddress* argument of
[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pDialableAddress* parameter is not a valid pointer. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *pDialableAddress* parameter.

The availability of this value depends on the service provider. For example, on an address exposed by the Unimodem service provider, this method will return an empty string instead of a phone number.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[Dialable Addresses](https://learn.microsoft.com/windows/desktop/Tapi/address-ovr)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall)