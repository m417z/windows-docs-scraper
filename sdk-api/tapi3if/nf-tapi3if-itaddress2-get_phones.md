# ITAddress2::get_Phones

## Description

The
**get_Phones** method returns a VARIANT pointer to an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of phone objects corresponding to the phone devices that can be used with this address.

This method is intended for Visual Basic and scripting applications. C/C++ applications should use the
[EnumeratePhones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress2-enumeratephones) method instead.

## Parameters

### `pPhones` [out]

Pointer to a VARIANT containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface pointers.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A phone device declares itself as being available on all addresses that support audio terminals by the TSP setting the PHONEFEATURE_GENERICPHONE bit in the **dwPhoneFeatures** member of the
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure. A phone device can also declare itself as being preferred to an address or set of addresses by returning address/line IDs via
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) with device class tapi/line. If no phones are available for use with the address, this method produces an empty collection and returns S_OK.

TAPI calls the **AddRef** method on the
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface returned by **ITAddress2::get_Phones**. The application must call **Release** on the
**ITPhone** interface to free resources associated with it.

## See also

[EnumeratePhones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress2-enumeratephones)

[ITAddress2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress2)