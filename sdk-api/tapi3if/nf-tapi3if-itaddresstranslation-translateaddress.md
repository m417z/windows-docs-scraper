# ITAddressTranslation::TranslateAddress

## Description

The
**TranslateAddress** method creates the address translation information interface. The primary goal of the
**TranslateAddress** method is to obtain the *pDestAddress* string ([dialable address](https://learn.microsoft.com/windows/desktop/Tapi/address-ovr)) needed as a parameter for
[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall). The
**TranslateAddress** method returns the dialable address indirectly, as one of the properties of an
[ITAddressTranslationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslationinfo) object.

## Parameters

### `pAddressToTranslate` [in]

Pointer to **BSTR** containing address that requires translation.

### `lCard` [in]

Calling card used for translation.

### `lTranslateOptions` [in]

Indicator of translation options, see
[LINETRANSLATEOPTION__Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetranslateoption--constants).

### `ppTranslated` [out]

Pointer to newly created
[ITAddressTranslationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslationinfo) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppTranslated* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | The method failed for unknown reasons. |
| **E_INVALIDARG** | The *lTranslateOptions* value is not valid. |
| **TAPI_E_NODRIVER** | This address has no TSP associated with it. |
| **TAPI_E_REGISTRY_SETTING_CORRUPT** | The registry is corrupt. |
| **TAPI_E_OPERATIONFAILED** | The method failed with TAPI. |
| **TAPI_E_RESOURCEUNAVAIL** | The TSP is not available. |
| **TAPI_E_INVALCARD** | The card number is not valid. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for *pAddressToTranslate* and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

The
**TranslateAddress** method is a COM wrapper for the TAPI 2.1
[LineTranslateAddress](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslateaddress) function.

TAPI calls the **AddRef** method on the
[ITAddressTranslationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslationinfo) interface returned by **TranslateAddress**. The application must call **Release** on the
**ITAddressTranslationInfo** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[Dialable Addresses](https://learn.microsoft.com/windows/desktop/Tapi/address-ovr)

[ITAddressTranslation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslation)