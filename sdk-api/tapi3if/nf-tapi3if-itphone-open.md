# ITPhone::Open

## Description

The
**Open** method opens this phone device. The phone device remains open until the application calls
[ITPhone::Close](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-close) or until TAPI is shut down.

This method is analogous to the TAPI 2.*x*
[phoneOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneopen) function; please see the TAPI 2.*x* documentation for more information.

## Parameters

### `Privilege` [in]

The
[PHONE_PRIVILEGE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_privilege) descriptor for the application's privilege status with respect to the phone device.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

While a phone is open, the application receives events pertaining to the phone.

Also, a phone must be open with owner privilege for the application to set the state of the phone. Querying the state of the phone can typically be done even if the phone is not open; for more details, see the individual methods of the
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)