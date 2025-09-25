# SHGetSpecialFolderLocation function

## Description

[**SHGetSpecialFolderLocation** is not supported and may be altered or unavailable in the future. Instead, use [SHGetFolderLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderlocation).]

Retrieves a pointer to the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure of a special folder.

## Parameters

### `hwnd` [in]

Type: **HWND**

Reserved.

### `csidl` [in]

Type: **int**

A [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value that identifies the folder of interest.

### `ppidl` [out]

Type: **PIDLIST_ABSOLUTE***

A PIDL specifying the folder's location relative to the root of the namespace (the desktop). It is the responsibility of the calling application to free the returned IDList by using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[SHGetSpecialFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetspecialfolderpatha)