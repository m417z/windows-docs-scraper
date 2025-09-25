# ITAddressCapabilities::get_CallTreatments

## Description

The
**get_CallTreatments** method gets
[call treatments](https://learn.microsoft.com/windows/desktop/Tapi/linecalltreatment--constants). This method is provided for Automation client applications, such as those written in Visual Basic and scripting languages.

## Parameters

### `pVariant` [out]

Pointer to a **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of call treatments.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **TAPI_E_INVALCALLSTATE** | [Call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) must be CS_IDLE. |
| **E_NOTIMPL** | Method not implemented. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface returned by **ITAddressCapabilities::get_CallTreatments**. The application must call **Release** on the
**ITCallInfo** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddressCapabilities](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresscapabilities)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)