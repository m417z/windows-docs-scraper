# IWSManEx::SessionFlagUseKerberos

## Description

The [WSMan.WSMan.SessionFlagUseKerberos](https://learn.microsoft.com/windows/desktop/WinRM/wsman-sessionflagusekerberos) method returns the value of the authentication flag **WSManFlagUseKerberos** for use in the *flags* parameter of [IWSMan::CreateSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsman-createsession).

**WSManFlagUseKerberos** is a constant in the **__WSManSessionFlags** enumeration. For more information, see [Authentication Constants](https://learn.microsoft.com/windows/desktop/WinRM/authentication-constants).

## Parameters

### `flags` [out]

The value of the constant.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManEx](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanex)

[WSMan.WSMan.SessionFlagUseKerberos](https://learn.microsoft.com/windows/desktop/WinRM/wsman-sessionflagusekerberos)