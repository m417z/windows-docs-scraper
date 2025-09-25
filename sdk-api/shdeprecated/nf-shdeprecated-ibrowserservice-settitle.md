# IBrowserService::SetTitle

## Description

Deprecated. Sets the title of a browser window.

## Parameters

### `psv` [in]

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to an [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) that represents the browser's view. The view must be either the browser's current view or the pending view.

### `pszName` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the browser window's title as a Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.