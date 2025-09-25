# IKnownFolder::GetIDList

## Description

Gets the location of the Shell namespace folder in the IDList ([ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist)) form.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

Flags that specify special retrieval options. This value can be 0; otherwise, one or more of the [KNOWN_FOLDER_FLAG](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-known_folder_flag) values.

### `ppidl` [out]

Type: **PIDLIST_ABSOLUTE***

When this method returns, contains the address of an absolute PIDL. This parameter is passed uninitialized. The calling application is responsible for freeing this resource when it is no longer needed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Equivalent to [SHGetKnownFolderIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderidlist).

## See also

[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))

[SHGetKnownFolderIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderidlist)