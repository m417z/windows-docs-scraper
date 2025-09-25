# IFrameworkInputPane::Unadvise

## Description

Unregisters an app's input pane handler object so that it no longer receives notifications.

## Parameters

### `dwCookie` [in]

Type: **DWORD**

A cookie that identifies the handler. This value was obtained when you registered the handler through the [Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iframeworkinputpane-advise) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFrameworkInputPane](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iframeworkinputpane)