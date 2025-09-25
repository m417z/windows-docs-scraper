# ITBasicCallControl::Dial

## Description

The
**Dial** method dials the specified address.

## Parameters

### `pDestAddress` [in]

Pointer to **BSTR** representation of address to be dialed. The format must conform to a standard
[dialable address](https://learn.microsoft.com/windows/desktop/Tapi/address-ovr).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pDestAddress* parameter is not a valid pointer. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pDestAddress* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

In some cases, the application may need to use the address translation interfaces (
[ITAddressTranslation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslation) and
[ITAddressTranslationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslationinfo)) to obtain a *pDestAddress* string in the proper format.

The
**Dial** method differs from
[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall) in that the call already exists. An example use is dialing an extension.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[Dial overview](https://learn.microsoft.com/windows/desktop/Tapi/dial-ovr)

[Dialable Addresses](https://learn.microsoft.com/windows/desktop/Tapi/address-ovr)

[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall)

[ITAddressTranslation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslation)

[ITAddressTranslationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslationinfo)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial)