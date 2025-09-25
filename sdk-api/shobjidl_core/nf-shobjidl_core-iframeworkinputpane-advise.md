# IFrameworkInputPane::Advise

## Description

Registers the app's input pane handler object to receive notifications on behalf of a window when an event triggers the input pane. This method differs from [AdviseWithHWND](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iframeworkinputpane-advisewithhwnd) in that it references its window through an object that implements [ICoreWindow](https://learn.microsoft.com/uwp/api/windows.ui.core.icorewindow).

## Parameters

### `pWindow` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the window (an object that implements [ICoreWindow](https://learn.microsoft.com/uwp/api/windows.ui.core.icorewindow)) for which the handler should listen for input pane events.

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

[IFrameworkInputPane::AdviseWithHWND](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iframeworkinputpane-advisewithhwnd)

[IFrameworkInputPane::Unadvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iframeworkinputpane-unadvise)