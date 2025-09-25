# IBrowserService::NotifyRedirect

## Description

Deprecated. Updates the browser to the specified pointer to an item identifier list (PIDL), navigating if necessary. This method is called when a page is redirected.

## Parameters

### `psv` [in]

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to an [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) that indicates the browser's view. The view must be either the browser's current view or the pending view.

### `pidl` [in]

Type: **LPCITEMIDLIST**

The PIDL to use in the update.

### `pfDidBrowse` [out]

Type: **BOOL***

Optional. A pointer to a value of type **BOOL** that indicates whether navigation occurred.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.