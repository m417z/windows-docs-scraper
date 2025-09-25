# IWSManEx3::SessionFlagUseCredSsp

## Description

Returns the value of the authentication flag **WSManFlagUseCredSsp** for use in the *flags* parameter of [IWSMan::CreateSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsman-createsession).

**WSManFlagUseCredSsp** is a constant in the **__WSManSessionFlags** enumeration. For more information, see [Authentication Constants](https://learn.microsoft.com/windows/desktop/WinRM/authentication-constants).

## Parameters

### `flags` [out, retval]

Specifies the authentication flag to use.

## Return value

If the method succeeds, it returns the authentication flag. Otherwise, it returns an HRESULT error code.

## See also

[IWSManEx3](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanex3)