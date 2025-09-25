# IFrameworkInputPane::AdviseWithHWND

## Description

Registers the app's input pane handler object to receive notifications on behalf of a window when an event triggers the input pane. This method differs from [Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iframeworkinputpane-advise) in that it references its window through an **HWND**.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the window for which the handler should listen for input pane events.

### `pHandler` [in]

Type: **[IFrameworkInputPaneHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iframeworkinputpanehandler)***

An [IFrameworkInputPaneHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iframeworkinputpanehandler) interface pointer to the handler instance for this app.

### `pdwCookie` [out]

Type: **DWORD***

A pointer to a value that, when this method returns successfully, receives a cookie for that can be used later to unregister the handler through the [Unadvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iframeworkinputpane-unadvise) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFrameworkInputPane](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iframeworkinputpane)

[IFrameworkInputPane::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iframeworkinputpane-advise)

[IFrameworkInputPane::Unadvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iframeworkinputpane-unadvise)