# SHGetKnownFolderPath function

## Description

Retrieves the full path of a known folder identified by the folder's [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid).

## Parameters

### `rfid` [in]

Type: **REFKNOWNFOLDERID**

A reference to the [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) that identifies the folder.

### `dwFlags` [in]

Type: **DWORD**

Flags that specify special retrieval options. This value can be 0; otherwise, one or more of the [KNOWN_FOLDER_FLAG](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-known_folder_flag) values.

### `hToken` [in, optional]

Type: **HANDLE**

An [access token](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens) that represents a particular user. If this parameter is **NULL**, which is the most common usage, the function requests the known folder for the current user.

Request a specific user's folder by passing the *hToken* of that user. This is typically done in the context of a service that has sufficient privileges to retrieve the token of a given user. That token must be opened with [TOKEN_QUERY](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects) and [TOKEN_IMPERSONATE](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects) rights. In some cases, you also need to include [TOKEN_DUPLICATE](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects). In addition to passing the user's *hToken*, the registry hive of that specific user must be mounted. See [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control) for further discussion of access control issues.

Assigning the *hToken* parameter a value of -1 indicates the Default User. This allows clients of **SHGetKnownFolderPath** to find folder locations (such as the **Desktop** folder) for the Default User. The Default User user profile is duplicated when any new user account is created, and includes special folders such as **Documents** and **Desktop**. Any items added to the Default User folder also appear in any new user account. Note that access to the Default User folders requires administrator privileges.

### `ppszPath` [out]

Type: **PWSTR***

When this method returns, contains the address of a pointer to a null-terminated Unicode string that specifies the path of the known folder. The calling process is responsible for freeing this resource once it is no longer needed by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree), whether **SHGetKnownFolderPath** succeeds or not. The returned path does not include a trailing backslash. For example, "C:\Users" is returned rather than "C:\Users\\".

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Among other things, this value can indicate that the *rfid* parameter references a [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) which does not have a path (such as a folder marked as [KF_CATEGORY_VIRTUAL](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category)). |
| **E_INVALIDARG** | Among other things, this value can indicate that the *rfid* parameter references a [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) that is not present on the system. Not all **KNOWNFOLDERID** values are present on all systems. Use [IKnownFolderManager::GetFolderIds](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-getfolderids) to retrieve the set of **KNOWNFOLDERID** values for the current system. |

## Remarks

This function replaces [SHGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha). That older function is now simply a wrapper for **SHGetKnownFolderPath**.

## See also

[IKnownFolder::GetPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfolder-getpath)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))

[SHGetKnownFolderIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderidlist)

[SHSetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shsetknownfolderpath)