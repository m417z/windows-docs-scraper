# IShellWindows::RegisterPending

## Description

Registers a pending window as a Shell window; the window is specified by an absolute PIDL.

## Parameters

### `lThreadId`

A thread ID.

### `pvarloc` [in]

Type: **VARIANT***

A [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) of type VT_VARIANT | VT_BYREF. Set the value of *pvarloc* to an absolute [PIDL](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) (PIDLIST_ABSOLUTE) that specifies the window to register.

### `pvarlocRoot` [in]

Type: **VARIANT***

Must be **NULL** or of type VT_EMPTY.

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

Use this method to register a window that is pending open; if the window is already open, use [IShellWindows::Register](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-register) instead. Use [IShellWindows::Revoke](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-revoke) to un-register a window.

## See also

[IShellWindows](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-ishellwindows)

[IShellWindows::Register](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-register)

[IShellWindows::Revoke](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-revoke)