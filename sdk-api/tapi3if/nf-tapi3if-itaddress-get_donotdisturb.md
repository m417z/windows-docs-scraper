# ITAddress::get_DoNotDisturb

## Description

The
**get_DoNotDisturb** method gets the current status of the do not disturb feature on the address. The do not disturb feature may not be available on all addresses.

## Parameters

### `pfDoNotDisturb` [out]

If VARIANT_TRUE, the do not disturb feature has been activated. If VARIANT_FALSE, the do not disturb feature is not active.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OPERATIONUNAVAIL** | Operation unavailable. |
| **TAPI_E_NOTSUPPORTED** | This operation is not supported on this address. |
| **E_POINTER** | The *pfDoNotDisturb* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

For programmers familiar with TAPI 2.*x:* The DoNotDisturb feature is implemented using the "forward" feature, if present on the address. When
**get_DoNotDisturb** is called, Tapi3.dll gets the
[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus) of the address object, and looks for its
[LINEFORWARD](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforward) entries. If one such entry is found and if its *dwDestAddressOffset* member is 0 (zero), then DoNotDisturb is considered to be turned ON, and therefore VARIANT_TRUE is returned as the value for this method.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[put_DoNotDisturb](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-put_donotdisturb)