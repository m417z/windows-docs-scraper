# ITAddressCapabilities::get_AddressCapabilityString

## Description

The
**get_AddressCapabilityString** method gets the capability string for a given
[ADDRESS_CAPABILITY_STRING](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-address_capability_string).

## Parameters

### `AddressCapString` [in]

Descriptor for desired address capability string.

### `ppCapabilityString` [out]

Pointer to **BSTR** value of address capability. **NULL** is a possible return value if the TSP does not provide a value for *AddressCapString*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *AddressCapString* parameter is not valid. |
| **E_POINTER** | The *ppCapabilityString* parameter is not a valid pointer. |
| **TAPI_E_NOTSUPPORTED** | TAPI version is not 3.0 or higher. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppCapabilityString* parameter.

## See also

[ADDRESS_CAPABILITY_STRING](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-address_capability_string)

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddressCapabilities](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresscapabilities)