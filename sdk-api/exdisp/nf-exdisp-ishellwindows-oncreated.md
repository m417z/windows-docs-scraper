# IShellWindows::OnCreated

## Description

Occurs when a new Shell window is created for a frame.

## Parameters

### `lCookie` [in]

Type: **long**

The cookie that identifies the window.

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

The address of the new window's [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A window is granted a cookie when it is registered as a Shell window. For more information, see [IShellWindows::Register](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-register).

## See also

[IShellWindows](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-ishellwindows)

[IShellWindows::OnActivated](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-onactivated)

[IShellWindows::OnNavigate](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-onnavigate)