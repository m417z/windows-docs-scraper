# ITPhone::get_Privilege

## Description

The
**get_Privilege** method retrieves the privilege of the open phone.

The application must call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before invoking this method; otherwise, the invocation fails.

## Parameters

### `pPrivilege` [out]

The
[PHONE_PRIVILEGE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_privilege) descriptor for the application's privilege status with respect to the phone device.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)