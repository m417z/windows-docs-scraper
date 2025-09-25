# SHGetFolderLocation function

## Description

Deprecated. Retrieves the path of a folder as an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Parameters

### `hwnd` [in]

Type: **HWND**

Reserved.

### `csidl` [in]

Type: **int**

A [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value that identifies the folder to be located. The folders associated with the CSIDLs might not exist on a particular system.

### `hToken` [in]

Type: **HANDLE**

An [access token](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens) that can be used to represent a particular user. It is usually set to **NULL**, but it may be needed when there are multiple users for those folders that are treated as belonging to a single user. The most commonly used folder of this type is **My Documents**. The calling application is responsible for correct impersonation when *hToken* is non-**NULL**. It must have appropriate security privileges for the particular user, and the user's registry hive must be currently mounted. See [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control) for further discussion of access control issues.

Assigning the *hToken* parameter a value of -1 indicates the Default User. This allows clients of **SHGetFolderLocation** to find folder locations (such as the Desktop folder) for the Default User. The Default User user profile is duplicated when any new user account is created, and includes special folders such as **My Documents** and **Desktop**. Any items added to the Default User folder also appear in any new user account.

### `dwFlags` [in]

Type: **DWORD**

### `ppidl` [out]

Type: **PIDLIST_ABSOLUTE***

The address of a pointer to an item identifier list structure that specifies the folder's location relative to the root of the namespace (the desktop). The *ppidl* parameter is set to **NULL** on failure. The calling application is responsible for freeing this resource by calling [ILFree](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilfree).

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) in *nFolder* is valid but the folder does not exist. |
| **E_INVALIDARG** | The [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) in *nFolder* is not valid. |

## Remarks

**Note** As of Windows Vista, this function is merely a wrapper for [SHGetKnownFolderIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderidlist). The CSIDL value is translated to its associated [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) and **SHGetKnownFolderIDList** is called. New applications should use the known folder system rather than the older CSIDL system, which is supported only for backward compatibility.

The **SHGetFolderLocation**, [SHGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha), [SHGetSpecialFolderLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetspecialfolderlocation), and [SHGetSpecialFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetspecialfolderpatha) functions are the preferred ways to obtain handles to folders on systems earlier than Windows Vista. Functions such as [ExpandEnvironmentStrings](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) that use the environment variable names directly, in the form %VariableName%, may not be reliable.

This function is a superset of [SHGetSpecialFolderLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetspecialfolderlocation), included with earlier versions of the Shell.

## See also

[IKnownFolder::GetIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfolder-getidlist)