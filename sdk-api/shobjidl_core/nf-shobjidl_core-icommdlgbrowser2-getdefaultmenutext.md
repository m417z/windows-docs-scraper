# ICommDlgBrowser2::GetDefaultMenuText

## Description

Called by the Shell view to get the default shortcut menu text.

## Parameters

### `ppshv`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to the [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface of the hosted view.

### `pszText`

Type: **WCHAR***

A pointer to a buffer that is used by the Shell browser to return the default shortcut menu text.

### `cchMax`

Type: **int**

The size of the *pszText* buffer, in characters. It should be at least the maximum allowable path length (MAX_PATH) in size.

## Return value

Type: **HRESULT**

Returns S_OK if a new default shortcut menu text was returned in *pshv*. If S_FALSE is returned, use the normal default text. Otherwise, returns a standard COM error value.