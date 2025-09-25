# ITAddress2::EnumeratePreferredPhones

## Description

The
**EnumeratePreferredPhones** method enumerates the preferred phone objects for this address.

This method is intended for C/C++ applications. Visual Basic and scripting applications must use the
[get_PreferredPhones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress2-get_preferredphones) method.

## Parameters

### `ppEnumPhone` [out]

Pointer to the location where, on success, this method will place a pointer to an enumeration object that contains the returned list of phones.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnumPhone* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | There is not enough memory to allocate the enumeration object. |

## Remarks

A phone device declares itself as being preferred to an address or set of addresses by returning address/line IDs using
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) with device class tapi/line. If no phones are available for use with the address, this method produces an empty enumeration and returns S_OK.

TAPI calls the **AddRef** method on the
[IEnumPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumphone) interface returned by **ITAddress2::EnumeratePreferredPhones**. The application must call **Release** on the
**IEnumPhone** interface to free resources associated with it.

## See also

[IEnumPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumphone)

[ITAddress2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress2)