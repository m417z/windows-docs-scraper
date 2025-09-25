# ITAddress::Forward

## Description

The
Forward method forwards calls destined for the address according to the forwarding instructions contained in
[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation). If *pForwardInfo* is set to **NULL**, forwarding is canceled.

## Parameters

### `pForwardInfo` [in]

Pointer to
[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation) interface, or set to **NULL** to cancel forwarding.

### `pCall` [in]

Pointer to
[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol) interface for the consultation call, if required by the telephony environment. May be **NULL** if not required.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The address does not support forwarding, or *pCall* does not point to a valid call. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pForwardInfo* or *pCall* parameter is not a valid pointer. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |
| **LINEERR_** | See [LineForward](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineforward) for error codes returned from this TAPI 2.1 function. |

## Remarks

The information in *pForwardInfo* overrides any previous forwarding instructions.

If
[ITAddress::put_DoNotDisturb](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-put_donotdisturb) is called with *fDoNotDisturb* set to VARIANT_FALSE, all forwarding is canceled.

An application can determine whether non-**NULL** consultation call is required by calling
[ITAddressCapabilities::get_AddressCapability](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddresscapabilities-get_addresscapability) (AC_ADDRESSCAPFLAGS, *plCapability*) and checking whether the flag LINEADDRCAPFLAGS_FWDCONSULT, a member of
[LINEADDRCAPFLAGS_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddrcapflags--constants), has been set in *plCapability*. If it is set, a non-**NULL** value is required for the *pCall* parameter of the
Forward method.

The
Forward method is, in part, a COM wrapper for the TAPI 2.1
[LineForward](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineforward) function.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[Forward overview](https://learn.microsoft.com/windows/desktop/Tapi/forward-ovr)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITAddress::CreateForwardInfoObject](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createforwardinfoobject)

[ITAddress::get_CurrentForwardInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_currentforwardinfo)

[ITForwardInformation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itforwardinformation)

[LineForward](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineforward)