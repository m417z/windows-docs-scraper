# IShellWindows::OnActivated

## Description

Occurs when a Shell window's activation state changes.

## Parameters

### `lCookie` [in]

Type: **long**

The cookie that identifies the window.

### `fActive` [in]

Type: **VARIANT_BOOL**

**TRUE** if the window is being activated; **FALSE** if the window is being deactivated.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A window is granted a cookie when it is registered as a Shell window. For more information, see [IShellWindows::Register](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-register).

## See also

[IShellWindows](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-ishellwindows)

[IShellWindows::OnCreated](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-oncreated)

[IShellWindows::OnNavigate](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-onnavigate)