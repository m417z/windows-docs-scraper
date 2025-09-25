# ITAddress::get_ServiceProviderName

## Description

The
**get_ServiceProviderName** method gets the name of the Telephony Service Provider (TSP) that supports this address: for example, Unimdm.tsp for the Unimodem service provider or H323.tsp for the H323 service provider.

## Parameters

### `ppName` [out]

Pointer to **BSTR** containing the service provider name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppName* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_NODRIVER** | No service provider was found that supports the current address. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppName* parameter.

You can retrieve the name of the provider in a TSP-dependent format using
[ITAddressCapabilities::get_AddressCapabilityString](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddresscapabilities-get_addresscapabilitystring) with *AddressCapString* set to ACS_PROVIDERSPECIFIC, which returns the string found in the **dwProviderInfoOffset** member of the TAPI 2.*x*
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITAddressCapabilities::get_AddressCapabilityString](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddresscapabilities-get_addresscapabilitystring)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)