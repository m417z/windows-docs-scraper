# SHCreateItemInKnownFolder function

## Description

Creates a Shell item object for a single file that exists inside a known folder.

## Parameters

### `kfid` [in]

Type: **REFKNOWNFOLDERID**

A reference to the [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid), a **GUID** that identifies the folder that contains the item.

### `dwKFFlags`

Type: **DWORD**

Flags that specify special options in the object retrieval. This value can be 0; otherwise, one or more of the [KNOWN_FOLDER_FLAG](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-known_folder_flag) values.

### `pszItem` [in, optional]

Type: **PCWSTR**

A pointer to a null-terminated buffer that contains the file name of the new item as a Unicode string. This parameter can also be **NULL**. In this case, an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that represents the known folder itself is created.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface that represents the item, retrieved through *ppv*. This value is typically IID_IShellItem or IID_IShellItem2.

### `ppv` [out]

Type: **void****

When this function returns successfully, contains the interface pointer requested in *riid*. This is typically [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or [IShellItem2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem2).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))