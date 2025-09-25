# IKnownFolder::SetPath

## Description

Assigns a new path to a known folder.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

Either zero or the following value:

#### KF_FLAG_DONT_UNEXPAND

Set the full path without environment strings. If this flag is not set, portions of the path at *pszPath* may be represented by environment strings such as `%USERPROFILE%`.

### `pszPath` [in]

Type: **LPCWSTR**

Pointer to the folder's new path. This is a null-terminated Unicode string of length MAX_PATH. This path cannot be of zero length. If this value is **NULL**, the **IKnownFolder::SetPath** sets the path to the default value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method cannot be called on folders of type [KF_CATEGORY_FIXED](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category) or [KF_CATEGORY_VIRTUAL](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category).

To call this method on a folder of type [KF_CATEGORY_COMMON](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category), the calling application must be running with elevated privileges.

This method is equivalent to [SHSetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shsetknownfolderpath).

## See also

[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))

[SHSetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shsetknownfolderpath)