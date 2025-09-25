# IShellWindows::Register

## Description

Registers an open window as a Shell window; the window is specified by handle.

## Parameters

### `pid` [in]

Type: **[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)***

The window's [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface.

### `hwnd` [in]

Type: **long**

A handle that specifies the window to register.

### `swClass` [in]

Type: **int**

A member of [ShellWindowTypeConstants](https://learn.microsoft.com/windows/desktop/api/exdisp/ne-exdisp-shellwindowtypeconstants) that specifies the type of window.

### `plCookie` [out]

Type: **long***

The window's cookie.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In the context of the Shell windows collection, a *cookie* is a token that uniquely identifies a registered Shell window.

Use this method to register an open window; if the window is pending open, use [IShellWindows::RegisterPending](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-registerpending) instead.

## See also

[IShellWindows](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-ishellwindows)

[IShellWindows::RegisterPending](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-registerpending)

[IShellWindows::Revoke](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-revoke)