# ITAddressCapabilities::get_AddressCapability

## Description

The
**get_AddressCapability** method gets the capability value for a given
[ADDRESS_CAPABILITY](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-address_capability).

## Parameters

### `AddressCap` [in]

Descriptor for desired address capability.

### `plCapability` [out]

Value of address capability.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *AddressCap* parameter is not valid. |
| **E_POINTER** | The *plCapability* parameter in not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ADDRESS_CAPABILITY](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-address_capability)

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddressCapabilities](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresscapabilities)