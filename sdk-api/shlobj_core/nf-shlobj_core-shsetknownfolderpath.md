# SHSetKnownFolderPath function

## Description

Redirects a known folder to a new location.

## Parameters

### `rfid` [in]

Type: **REFKNOWNFOLDERID**

A **GUID** that identifies the known folder.

### `dwFlags` [in]

Type: **DWORD**

Either 0 or the following value.

#### KF_FLAG_DONT_UNEXPAND

If this flag is set, portions of the path referenced by *pszPath* may be represented by environment strings such as `%USERPROFILE%`.

### `hToken` [in]

Type: **HANDLE**

An [access token](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens) used to represent a particular user. This parameter is usually set to **NULL**, in which case the function tries to access the current user's instance of the folder. However, you may need to assign a value to *hToken* for those folders that can have multiple users but are treated as belonging to a single user. The most commonly used folder of this type is **Documents**.

The calling application is responsible for correct impersonation when *hToken* is non-null. It must have appropriate security privileges for the particular user, including TOKEN_QUERY and TOKEN_IMPERSONATE, and the user's registry hive must be currently mounted. See [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control) for further discussion of access control issues.

Assigning the *hToken* parameter a value of -1 indicates the Default User. This allows clients of **SHSetKnownFolderPath** to set folder locations (such as the **Desktop** folder) for the Default User. The Default User user profile is duplicated when any new user account is created, and includes special folders such as **Documents** and **Desktop**. Any items added to the Default User folder also appear in any new user account. Note that access to the Default User folders requires administrator privileges.

### `pszPath` [in]

Type: **PCWSTR**

A pointer to the folder's new path. This is a null-terminated Unicode string of length MAX_PATH. This path cannot be of zero length.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Among other things, this value can indicate that the *rfid* parameter references a [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) that is not present on the system. Not all **KNOWNFOLDERID** values are present on all systems. Use [IKnownFolderManager::GetFolderIds](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-getfolderids) to retrieve the set of **KNOWNFOLDERID** values for the current system. |

## Remarks

This function replaces [SHSetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shsetfolderpatha). That older function is now simply a wrapper for **SHSetKnownFolderPath**.

The caller of this function must have Administrator privileges. To call this function on public known folders, the caller must have Administrator privileges. For per-user known folders the caller only requires User privileges.

Some of the known folders, for example, the **Documents** folder, are per-user. Every user has a different path for their **Documents** folder. If *hToken* is **NULL**, the API tries to access the calling application's instance of the folder, which is that of the current user. If *hToken* is a valid user token, the API tries to impersonate the user using this token and tries to access that user's instance.

This function cannot be called on folders of type [KF_CATEGORY_FIXED](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category) and [KF_CATEGORY_VIRTUAL](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category).

To call this function on a folder of type [KF_CATEGORY_COMMON](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category), the calling application must be running with elevated privileges.

## See also

[IKnownFolder::GetPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfolder-getpath)

[IKnownFolder::SetPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfolder-setpath)

[IKnownFolderManager::Redirect](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-redirect)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))

[SHGetKnownFolderIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderidlist)

[SHGetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath)