# ITPhone::Close

## Description

The
**Close** method closes this phone device. The phone device remains closed until the application calls the
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) method. For more information, see the following Remarks section.

This method is analogous to the TAPI 2.*x*
[phoneOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneopen) function; please see the TAPI 2.*x* documentation for more information.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

While a phone is closed, the application does not receive events pertaining to the phone.

A phone must be open with owner privilege for the application to set the state of the phone. Querying the state of the phone can typically be done even if the phone is not open; for more details, see the individual methods of the
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface.

After the phone device has been successfully closed, any
[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol) interface pointer obtained for this phone object is no longer valid.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)