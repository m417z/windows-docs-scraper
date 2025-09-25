# ITPhone::get_PreferredAddresses

## Description

The
**get_PreferredAddresses** method returns a collection of addresses that the phone is preferred for use on. The application does not have to call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before executing this method.

This method is intended for Visual Basic and scripting applications. C/C++ applications will find it more convenient to use the
[EnumerateAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-enumerateaddresses) method.

## Parameters

### `pAddresses` [out]

Pointer to a **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface pointers.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pAddresses* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | There is not enough memory to allocate the collection object. |

## Remarks

If no usable addresses are present on the system, this method returns an empty collection.

A phone device declares itself as being preferred to an address or set of addresses by returning address/line IDs using the TAPI 2.x
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) function with device class tapi/line.

Although the
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) function requires the handle to an open phone device, the application does not have to call the
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) method before calling
[EnumeratePreferredAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-enumeratepreferredaddresses). This is because the implementation of the phone object can open the phone and call
**phoneGetID** during TAPI initialization or when a new phone object appears.

TAPI calls the **AddRef** method on the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface returned by **ITPhone::get_PreferredAddresses**. The application must call **Release** on the
**ITAddress** interface to free resources associated with it.

## See also

[EnumeratePreferredAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-enumeratepreferredaddresses)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[get_Addresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_addresses)

[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid)