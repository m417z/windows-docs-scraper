# ITAddress2::get_PreferredPhones

## Description

The
**get_PreferredPhones** method returns a collection of phone objects corresponding to the phone devices that are preferred for use with this address.

This method is intended for Visual Basic and scripting applications. C/C++ applications should use the
[EnumeratePreferredPhones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress2-enumeratepreferredphones) method instead.

## Parameters

### `pPhones` [out]

Pointer to a **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface pointers.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pPhones* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | There is not enough memory to allocate the collection object. |

## Remarks

A phone device declares itself as being preferred to an address or set of addresses by returning address/line IDs using
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) with device class tapi/line. If no phones are available for use with this address, the method produces an empty collection and returns S_OK.

TAPI calls the **AddRef** method on the
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface returned by **ITAddress2::get_PreferredPhones**. The application must call **Release** on the
**ITPhone** interface to free resources associated with it.

## See also

[ITAddress2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress2)

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)