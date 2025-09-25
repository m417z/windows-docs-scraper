# ITAddressTranslationInfo::get_DestinationCountryCode

## Description

The
**get_DestinationCountryCode** method retrieves the country/region code for the call destination.

## Parameters

### `CountryCode` [out]

A pointer to destination country/region code.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *CountryCode* parameter is an invalid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

Corresponds to the **dwDestCountry** member of the TAPI 2
[LINETRANSLATEOUTPUT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslateoutput) structure.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddressTranslationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslationinfo)