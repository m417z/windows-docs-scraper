# ITAddressTranslation::get_Locations

## Description

The
**get_Locations** method creates a collection of currently available address locations. This method is provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateLocations](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddresstranslation-enumeratelocations) method.

## Parameters

### `pVariant` [out]

Pointer to **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITLocationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlocationinfo) interface pointers (location objects).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The
**get_Locations** method is a COM wrapper for the TAPI 2.1
[LineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps) function, and takes location information from the
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure returned by that function.

TAPI calls the **AddRef** method on the
[ITLocationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlocationinfo) interface returned by **ITAddressTranslation::get_Locations**. The application must call **Release** on the
**ITLocationInfo** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[EnumerateLocations](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddresstranslation-enumeratelocations)

[ITAddressTranslation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslation)

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)

[ITLocationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlocationinfo)