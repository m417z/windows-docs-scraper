# ITAddress::get_State

## Description

The
**get_State** method gets the current state of the address in *pAddressState*.

## Parameters

### `pAddressState` [out]

Pointer to a member of
[ADDRESS_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-address_state).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pAddressState* parameter is not a valid pointer. |

## See also

[ADDRESS_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-address_state)

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)