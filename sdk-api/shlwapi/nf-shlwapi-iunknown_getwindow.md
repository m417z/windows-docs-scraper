# IUnknown_GetWindow function

## Description

Attempts to retrieve a window handle from a Component Object Model (COM) object by querying for various interfaces that have a **GetWindow** method.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the COM object from which this function will attempt to obtain a window handle.

### `phwnd` [out]

Type: **HWND***

A pointer to a HWND that, when this function returns successfully, receives the window handle. If a window handle was not obtained, this parameter is set to **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if a window handle was successfully returned, or a COM error code otherwise. If no suitable interface was found, the function returns E_NOINTERFACE. Otherwise, the function returns the **HRESULT** returned by the corresponding interface's **GetWindow** method.

## Remarks

This function attempts to retrieve the window handle by calling [IOleWindow::GetWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolewindow-getwindow), [IInternetSecurityMgrSite::GetWindow](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms537095(v=vs.85)), and [IShellView::GetWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview). It is possible that future versions of **IUnknown_GetWindow** may attempt additional interfaces.

**Note** The query for [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) is theoretically unnecessary because **IShellView** derives from [IOleWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolewindow). The function explicitly queries for this interface because some objects implement [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) incorrectly and fail to respond to a query for the base interface.