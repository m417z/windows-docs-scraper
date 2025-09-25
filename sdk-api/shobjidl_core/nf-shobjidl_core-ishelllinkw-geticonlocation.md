# IShellLinkW::GetIconLocation

## Description

Gets the location (path and index) of the icon for a Shell link object.

## Parameters

### `pszIconPath`

Type: **LPTSTR**

The address of a buffer that receives the path of the file containing the icon.

### `cch`

Type: **int**

The maximum number of characters to copy to the buffer pointed to by the *pszIconPath* parameter.

### `piIcon`

Type: **int***

The address of a value that receives the index of the icon.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.