# IShellWindows::OnNavigate

## Description

Occurs when a Shell window is navigated to a new location.

## Parameters

### `lCookie` [in]

Type: **long**

The cookie that identifies the window.

### `pvarLoc` [in]

Type: **VARIANT***

A [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) of type VT_VARIANT | VT_BYREF. Set the value of *pvarLoc* to an absolute [PIDL](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) (PIDLIST_ABSOLUTE) that specifies the new location.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A window is granted a cookie when it is registered as a Shell window. For more information, see [IShellWindows::Register](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-register).

## See also

[IShellWindows](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-ishellwindows)

[IShellWindows::OnActivated](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-onactivated)

[IShellWindows::OnCreated](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-oncreated)