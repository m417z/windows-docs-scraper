# ITPhone::EnumerateAddresses

## Description

The
**EnumerateAddresses** method enumerates the addresses that the phone can be used on. The application does not have to call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before executing this method.

This method is intended for C/C++ applications. Visual Basic and scripting applications must use the
[get_Addresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_addresses) method.

## Parameters

### `ppEnumAddress` [out]

Pointer to the
[IEnumAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumaddress) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If no phones are available for use with the address, this method produces an empty enumeration and returns S_OK.

A phone device declares itself as being available on all addresses that support audio terminals by the TSP setting the PHONEFEATURE_GENERICPHONE bit in the **dwPhoneFeatures** member of the
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure. A phone device can also declare itself as being preferred to an address or set of addresses by returning address/line IDs using
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) with device class tapi/line. The
**EnumerateAddresses** method returns addresses that have been identified both ways.

To get only addresses that the phone is preferred on, you can call the
[EnumeratePreferredAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-enumeratepreferredaddresses) method.

A phone device declares itself as being specific to an address or set of addresses by returning address/line IDs using
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) with device class tapi/line. Although the
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) function requires the handle to an open phone device, the application does not have to call the
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) method before calling
**EnumerateAddresses**. This is because the implementation of the phone object can open the phone and call
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) during TAPI initialization or when a new phone object appears.

TAPI calls the **AddRef** method on the
[IEnumAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumaddress) interface returned by **ITPhone::EnumerateAddresses**. The application must call **Release** on the
**IEnumAddress** interface to free resources associated with it.

## See also

[EnumeratePreferredAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-enumeratepreferredaddresses)

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)