# IWSManEx::SessionFlagSkipCACheck

## Description

The [WSMan.SessionFlagSkipCACheck](https://learn.microsoft.com/windows/desktop/WinRM/wsman-sessionflagskipcacheck) method returns the value of the **WSManFlagSkipCACheck** authentication flag for use in the *flags* parameter of the [IWSMan::CreateSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsman-createsession) method.

**WSManFlagSkipCACheck** is a constant in the **__WSManSessionFlags** enumeration. For more information, see [Authentication Constants](https://learn.microsoft.com/windows/desktop/WinRM/authentication-constants).

## Parameters

### `flags` [out]

The value of the constant.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManEx](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanex)

[WSMan.SessionFlagSkipCACheck](https://learn.microsoft.com/windows/desktop/WinRM/wsman-sessionflagskipcacheck)