# IWSManEx::SessionFlagUTF8

## Description

The [WSMan.SessionFlagUTF8](https://learn.microsoft.com/windows/desktop/WinRM/wsman-sessionflagutf8) method returns the value of the authentication flag **WSManFlagUTF8** for use in the *flags* parameter of [IWSMan::CreateSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsman-createsession).

**WSManFlagUTF8** is a constant in the **__WSManSessionFlags** enumeration. For more information, see [Other Session Constants](https://learn.microsoft.com/windows/desktop/WinRM/other-session-constants).

## Parameters

### `flags` [out]

The value of the constant.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManEx](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanex)

[WSMan.SessionFlagUTF8](https://learn.microsoft.com/windows/desktop/WinRM/wsman-sessionflagutf8)