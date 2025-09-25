# ITAddressTranslation::EnumerateLocations

## Description

The
**EnumerateLocations** method enumerates the currently available address locations. This method is provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_Locations](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddresstranslation-get_locations) method.

## Parameters

### `ppEnumLocation` [out]

Pointer to
[IEnumLocation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumlocation) object created.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnumLocations* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to create object. |

## Remarks

The
**EnumerateLocations** method is a COM wrapper for the TAPI 2.1
[LineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps) function, and takes location information from the
[LINETRANSLATECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetranslatecaps) structure returned by that function.

TAPI calls the **AddRef** method on the
[IEnumLocation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumlocation) interface returned by **ITAddressTranslation::EnumerateLocations**. The application must call **Release** on the
**IEnumLocation** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[IEnumLocation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumlocation)

[ITAddressTranslation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslation)