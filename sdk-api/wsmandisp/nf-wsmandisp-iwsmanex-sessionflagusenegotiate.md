# IWSManEx::SessionFlagUseNegotiate

## Description

The [WSMan.SessionFlagUseNegotiate](https://learn.microsoft.com/windows/desktop/WinRM/wsman-sessionflagusenegotiate) method returns the value of the authentication flag **WSManFlagUseNegotiate** for use in the *flags* parameter of [IWSMan::CreateSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsman-createsession).

**WSManFlagUseNegotiate** is a constant in the **__WSManSessionFlags** enumeration. For more information, see [Authentication Constants](https://learn.microsoft.com/windows/desktop/WinRM/authentication-constants).

## Parameters

### `flags` [out]

The value of the constant.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManEx](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanex)

[WSMan.SessionFlagUseNegotiate](https://learn.microsoft.com/windows/desktop/WinRM/wsman-sessionflagusenegotiate)