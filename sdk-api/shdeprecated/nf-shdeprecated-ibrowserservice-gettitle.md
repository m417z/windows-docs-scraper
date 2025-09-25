# IBrowserService::GetTitle

## Description

Deprecated. Retrieves the title of a browser window.

## Parameters

### `psv` [in]

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to an [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) that represents the browser's current view.

### `pszName` [out]

Type: **LPWSTR**

A pointer to a buffer that receives the title.

### `cchName` [in]

Type: **DWORD**

The size, in characters, of the buffer pointed to by *pszName*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.