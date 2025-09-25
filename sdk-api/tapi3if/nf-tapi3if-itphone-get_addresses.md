# ITPhone::get_Addresses

## Description

The
**get_Addresses** method returns a collection of addresses that the phone can be used on. The application does not have to call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before executing this method.

This method is intended for Visual Basic and scripting applications. C/C++ applications should use the
[EnumerateAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-enumerateaddresses) method instead.

## Parameters

### `pAddresses` [out]

Pointer to a VARIANT containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface pointers.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A phone device declares itself as being available on all addresses that support audio terminals by the TSP setting the PHONEFEATURE_GENERICPHONE bit in the **dwPhoneFeatures** member of the
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure. A phone device can also declare itself as being preferred to an address or set of addresses by returning address/line IDs using
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) with device class tapi/line. The
**get_Addresses** method returns addresses that have been identified both ways.

To get only addresses that the phone is preferred on, you can call the
[get_PreferredAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_preferredaddresses) method.

The application does not have to call the
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) method before calling
**get_Addresses**. This is because the implementation of the phone object can open the phone and call
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) during TAPI initialization or when a new phone object appears.

TAPI calls the **AddRef** method on the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface returned by **ITPhone::get_Addresses**. The application must call **Release** on the
**ITAddress** interface to free resources associated with it.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[get_PreferredAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_preferredaddresses)