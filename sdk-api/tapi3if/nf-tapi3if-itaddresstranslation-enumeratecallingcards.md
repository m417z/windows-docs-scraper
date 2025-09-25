# ITAddressTranslation::EnumerateCallingCards

## Description

The
**EnumerateCallingCards** method enumerates calling cards associated with the address. This method is provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_CallingCards](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddresstranslation-get_callingcards) method.

## Parameters

### `ppEnumCallingCard` [out]

Pointer to
[IEnumCallingCard](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcallingcard) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnumCallingCard* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

This method is a COM wrapper for the TAPI 2.1
[LineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps) function, and takes calling card information from the
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure returned by that function.

TAPI calls the **AddRef** method on the
[IEnumCallingCard](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcallingcard) interface returned by **ITAddressTranslation::EnumerateCallingCards**. The application must call **Release** on the
**IEnumCallingCard** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[IEnumCallingCard](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcallingcard)

[ITAddressTranslation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslation)