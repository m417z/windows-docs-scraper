# IKnownFolderManager::Redirect

## Description

Redirects folder requests for common and per-user folders.

## Parameters

### `rfid` [in]

Type: **REFKNOWNFOLDERID**

A reference to the [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) of the folder to be redirected.

### `hwnd` [in, optional]

Type: **HWND**

The handle of the parent window used to display copy engine progress UI dialogs when [KF_REDIRECT_WITH_UI](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_kf_redirect_flags) is passed in the *flags* parameter. If no progress dialog is needed, this value can be **NULL**.

### `flags` [in]

Type: **[KF_REDIRECT_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_kf_redirect_flags)**

The [KF_REDIRECT_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_kf_redirect_flags) options for redirection.

### `pszTargetPath` [in, optional]

Type: **LPCWSTR**

A pointer to the new path for the folder. This is a null-terminated Unicode string. This value can be **NULL**.

### `cFolders` [in]

Type: **UINT**

The number of [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) values in the array at *pExclusion*.

### `pExclusion` [in]

Type: **KNOWNFOLDERID const***

Pointer to an array of [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) values that refer to subfolders of *rfid* that should be excluded from the redirection. If no subfolders are excluded, this value can be **NULL**.

### `ppszError` [out]

Type: **LPWSTR***

When this method returns, contains the address of a pointer to a null-terminated Unicode string that contains an error message if one was generated. This value can be **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Among other things, this value can indicate that the *rfid* parameter references a [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) that is not present on the system. Not all **KNOWNFOLDERID** values are present on all systems. Use [IKnownFolderManager::GetFolderIds](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-getfolderids) to retrieve the set of **KNOWNFOLDERID** values for the current system. |

## See also

[IKnownFolderManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfoldermanager)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))