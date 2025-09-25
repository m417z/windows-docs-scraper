# ITAddress2::EnumeratePhones

## Description

The
**EnumeratePhones** method enumerates the phone objects corresponding to the phone devices that can be used with this address.

This method is intended for C/C++ applications. Visual Basic and scripting applications must use the
[get_Phones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress2-get_phones) method.

## Parameters

### `ppEnumPhone` [out]

Pointer to the new
[IEnumPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumphone) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnumPhone* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | The method failed for unknown reasons. |

## Remarks

A phone device declares itself as being available on all addresses that support audio terminals by the TSP setting the PHONEFEATURE_GENERICPHONE bit in the **dwPhoneFeatures** member of the
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure. A phone device can also declare itself as being preferred to an address or set of addresses by returning address/line IDs using
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) with device class tapi/line. If no phones are available for use with the address, this method produces an empty enumeration and returns S_OK.

TAPI calls the **AddRef** method on the
[IEnumPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumphone) interface returned by **ITAddress2::EnumeratePhones**. The application must call **Release** on the
**IEnumPhone** interface to free resources associated with it.

## See also

[IEnumPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumphone)

[ITAddress2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress2)