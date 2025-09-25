# IShellWindows::Revoke

## Description

Revokes a Shell window's registration and removes the window from the Shell windows collection.

## Parameters

### `lCookie` [in]

Type: **long***

The cookie that identifies the window to un-register.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In the context of the Shell windows collection, a *cookie* is a token that uniquely identifies a registered Shell window.

Use the [IShellWindows::Register](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-register) method to register an open window by handle. Use the [IShellWindows::RegisterPending](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-registerpending) method to register a pending-open window by absolute PIDL.

## See also

[IShellWindows](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-ishellwindows)

[IShellWindows::Register](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-register)

[IShellWindows::RegisterPending](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-registerpending)