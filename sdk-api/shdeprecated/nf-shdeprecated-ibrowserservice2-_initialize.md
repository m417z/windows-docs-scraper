# IBrowserService2::_Initialize

## Description

Deprecated. Coordinates the initializing of state between the base and the derived classes.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the current window.

### `pauto` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the outer object's [IWebBrowser2](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-iwebbrowser2) automation interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.