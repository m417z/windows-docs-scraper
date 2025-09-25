# IDefaultExtractIconInit::SetShortcutIcon

## Description

Sets the icon for a shortcut to the object.

## Parameters

### `pszFile` [in, optional]

Type: **LPCWSTR**

A pointer to a buffer that contains the full icon path, including the file name and extension, as a Unicode string. This pointer can be **NULL**.

### `iIcon`

Type: **int**

Shell icon ID.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.