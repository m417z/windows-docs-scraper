# SHGetKnownFolderIDList function

## Description

Retrieves the path of a known folder as an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Parameters

### `rfid` [in]

Type: **REFKNOWNFOLDERID**

A reference to the [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) that identifies the folder. The folders associated with the known folder IDs might not exist on a particular system.

### `dwFlags` [in]

Type: **DWORD**

Flags that specify special retrieval options. This value can be 0; otherwise, it is one or more of the [KNOWN_FOLDER_FLAG](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-known_folder_flag) values.

### `hToken` [in]

Type: **HANDLE**

An [access token](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens) used to represent a particular user. This parameter is usually set to **NULL**, in which case the function tries to access the current user's instance of the folder. However, you may need to assign a value to *hToken* for those folders that can have multiple users but are treated as belonging to a single user. The most commonly used folder of this type is **Documents**.

The calling application is responsible for correct impersonation when *hToken* is non-null. It must have appropriate security privileges for the particular user, including TOKEN_QUERY and TOKEN_IMPERSONATE, and the user's registry hive must be currently mounted. See [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control) for further discussion of access control issues.

Assigning the *hToken* parameter a value of -1 indicates the Default User. This allows clients of **SHGetKnownFolderIDList** to find folder locations (such as the **Desktop** folder) for the Default User. The Default User user profile is duplicated when any new user account is created, and includes special folders such as **Documents** and **Desktop**. Any items added to the Default User folder also appear in any new user account. Note that access to the Default User folders requires administrator privileges.

### `ppidl` [out]

Type: **PIDLIST_ABSOLUTE***

When this method returns, contains a pointer to the PIDL of the folder. This parameter is passed uninitialized. The caller is responsible for freeing the returned PIDL when it is no longer needed by calling [ILFree](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilfree).

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Among other things, this value can indicate that the *rfid* parameter references a [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) that is not present on the system. Not all **KNOWNFOLDERID** values are present on all systems. Use [IKnownFolderManager::GetFolderIds](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-getfolderids) to retrieve the set of **KNOWNFOLDERID** values for the current system. |

## Remarks

This function replaces [SHGetFolderLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderlocation). That older function is now simply a wrapper for **SHGetKnownFolderIDList**.

Callers using this function must have at least User privileges.

Some known folders, for example, the **Documents** folder, are per-user. Each user has a different path for the **Documents** folder. If *hToken* is **NULL**, the API tries to access the current user's instance of the folder. If *hToken* is a valid user token, the API tries to impersonate the user using this token, and attempts to access that user's instance of the folder.

## See also

[IKnownFolder::GetPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfolder-getpath)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))

[SHGetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath)

[SHSetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shsetknownfolderpath)