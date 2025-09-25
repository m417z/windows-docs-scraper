# IWSManEx::SessionFlagUseNoAuthentication

## Description

The
[WSMan.SessionFlagUseNoAuthentication](https://learn.microsoft.com/windows/desktop/WinRM/wsman-sessionflagusenoauthentication)
method returns the value of the authentication flag
**WSManFlagUseNoAuthentication** for use in the *flags* parameter of
[IWSMan::CreateSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsman-createsession).

**WSManFlagUseNoAuthentication** is a constant in the
**__WSManSessionFlags** enumeration. For more information, see
[Authentication Constants](https://learn.microsoft.com/windows/desktop/WinRM/authentication-constants).

## Parameters

### `flags` [out]

The value of the constant.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManEx](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanex)

[WSMan.SessionFlagUseNoAuthentication](https://learn.microsoft.com/windows/desktop/WinRM/wsman-sessionflagusenoauthentication)