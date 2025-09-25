# IAssocHandler::GetIconLocation

## Description

Retrieves the location of the icon associated with the application.

## Parameters

### `ppszPath` [out]

Type: **LPWSTR***

When this method returns, contains the address of a pointer to a null-terminated, Unicode string that contains the path to the application's icon.

### `pIndex` [out]

Type: **int***

When this method returns, contains a pointer to the index of the icon within the resource named in *ppszPath*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the icon cannot be found, the function will return the path to the executable, and an icon index of zero.

For performance reasons, an application may use the Shell image cache to retrieve the icon, rather than loading the icon directly from the path returned. The path and icon index can be passed directly to [Shell_GetCachedImageIndex](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shell_getcachedimageindexa). One benefit of this is that the Shell cache can provide a default icon in the event that no icon was available for the application.