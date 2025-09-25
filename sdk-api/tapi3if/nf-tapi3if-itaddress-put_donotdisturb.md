# ITAddress::put_DoNotDisturb

## Description

The
**put_DoNotDisturb** method sets the do not disturb status. The do not disturb feature may not be available on all addresses.

## Parameters

### `fDoNotDisturb` [in]

If VARIANT_TRUE, the do not disturb feature will be activated. If VARIANT_FALSE, the do not disturb feature will be deactivated and all forwarding canceled.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *fDoNotDisturb* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

The DoNotDisturb feature is implemented using forwarding. If
**put_DoNotDisturb** is called with VARIANT_TRUE, Tapi3.dll creates a
[LINEFORWARD](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforward) list with the mode set to LINEFORWARDMODE_UNCOND and only one LINEFORWARD item with the destination address set to **NULL**. If
**put_DoNotDisturb** is called with VARIANT_FALSE, Tapi3.dll cancels forwarding completely on this address, even those forwarding rules set with
[ITAddress::Forward](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-forward).

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[get_DoNotDisturb](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_donotdisturb)