# SHGetFolderPathW function

## Description

Deprecated. Gets the path of a folder identified by a [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value.

**Note** As of Windows Vista, this function is merely a wrapper for [SHGetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath). The CSIDL value is translated to its associated [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) and then **SHGetKnownFolderPath** is called. New applications should use the known folder system rather than the older CSIDL system, which is supported only for backward compatibility.

## Parameters

### `hwnd` [in]

Type: **HWND**

Reserved.

### `csidl` [in]

Type: **int**

A [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value that identifies the folder whose path is to be retrieved. Only real folders are valid. If a virtual folder is specified, this function fails. You can force creation of a folder by combining the folder's **CSIDL** with **CSIDL_FLAG_CREATE**.

### `hToken` [in]

Type: **HANDLE**

An [access token](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens) that can be used to represent a particular user.

**Microsoft Windows 2000 and earlier:** Always set this parameter to **NULL**.

**Windows XP and later:** This parameter is usually set to **NULL**, but you might need to assign a non-**NULL** value to *hToken* for those folders that can have multiple users but are treated as belonging to a single user. The most commonly used folder of this type is **Documents**.

The calling process is responsible for correct impersonation when *hToken* is non-**NULL**. The calling process must have appropriate security privileges for the particular user, including TOKEN_QUERY and TOKEN_IMPERSONATE, and the user's registry hive must be currently mounted. See [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control) for further discussion of access control issues.

Assigning the *hToken* parameter a value of -1 indicates the Default User. This enables clients of **SHGetFolderPath** to find folder locations (such as the Desktop folder) for the Default User. The Default User user profile is duplicated when any new user account is created, and includes special folders such as My Documents and Desktop. Any items added to the Default User folder also appear in any new user account.

### `dwFlags` [in]

Type: **DWORD**

Flags that specify the path to be returned. This value is used in cases where the folder associated with a [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) (or [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl)) can be moved, renamed, redirected, or roamed across languages by a user or administrator.

The known folder system that underlies **SHGetFolderPath** allows users or administrators to redirect a known folder to a location that suits their needs. This is achieved by calling [IKnownFolderManager::Redirect](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-redirect), which sets the "current" value of the folder associated with the SHGFP_TYPE_CURRENT flag.

The default value of the folder, which is the location of the folder if a user or administrator had not redirected it elsewhere, is retrieved by specifying the SHGFP_TYPE_DEFAULT flag. This value can be used to implement a "restore defaults" feature for a known folder.

For example, the default value (SHGFP_TYPE_DEFAULT) for [FOLDERID_Music](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) ([CSIDL_MYMUSIC](https://learn.microsoft.com/windows/desktop/shell/csidl)) is "C:\Users\**user name**\Music". If the folder was redirected, the current value (SHGFP_TYPE_CURRENT) might be "D:\Music". If the folder has not been redirected, then SHGFP_TYPE_DEFAULT and SHGFP_TYPE_CURRENT retrieve the same path.

#### SHGFP_TYPE_CURRENT

Retrieve the folder's current path.

#### SHGFP_TYPE_DEFAULT

Retrieve the folder's default path.

### `pszPath` [out]

Type: **LPWSTR**

A pointer to a **null**-terminated string of length MAX_PATH which will receive the path. If an error occurs or S_FALSE is returned, this string will be empty. The returned path does not include a trailing backslash. For example, "C:\Users" is returned rather than "C:\Users\\".

##### - dwFlags.SHGFP_TYPE_CURRENT

Retrieve the folder's current path.

##### - dwFlags.SHGFP_TYPE_DEFAULT

Retrieve the folder's default path.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is a superset of [SHGetSpecialFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetspecialfolderpatha).

Only some [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) values are supported, including the following:

* [CSIDL_ADMINTOOLS](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_APPDATA](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_COMMON_ADMINTOOLS](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_COMMON_APPDATA](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_COMMON_DOCUMENTS](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_COOKIES](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_FLAG_CREATE](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_FLAG_DONT_VERIFY](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_HISTORY](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_INTERNET_CACHE](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_LOCAL_APPDATA](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_MYPICTURES](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_PERSONAL](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_PROGRAM_FILES](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_PROGRAM_FILES_COMMON](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_SYSTEM](https://learn.microsoft.com/windows/desktop/shell/csidl)
* [CSIDL_WINDOWS](https://learn.microsoft.com/windows/desktop/shell/csidl)

#### Examples

The following code example uses **SHGetFolderPath** to find or create a folder and then creates a file in it.

```cpp
TCHAR szPath[MAX_PATH];

if(SUCCEEDED(SHGetFolderPath(NULL,
                             CSIDL_PERSONAL|CSIDL_FLAG_CREATE,
                             NULL,
                             0,
                             szPath)))
{
    PathAppend(szPath, TEXT("New Doc.txt"));
    HANDLE hFile = CreateFile(szPath, ...);
}
```

> [!NOTE]
> The shlobj_core.h header defines SHGetFolderPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[IKnownFolder::GetPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfolder-getpath)