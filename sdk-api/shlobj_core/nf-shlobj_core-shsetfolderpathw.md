# SHSetFolderPathW function

## Description

Deprecated. Assigns a new path to a system folder identified by its CSIDL.

## Parameters

### `csidl` [in]

Type: **int**

A [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value that identifies the folder whose path is to be set. Only physical folders are valid. If a virtual folder is specified, this function fails.

Add the [CSIDL_FLAG_DONT_UNEXPAND](https://learn.microsoft.com/windows/desktop/shell/csidl) value to the CSIDL to ensure that the string is written to the registry exactly as provided. If the [CSIDL_FLAG_DONT_UNEXPAND](https://learn.microsoft.com/windows/desktop/shell/csidl) flag is not included, portions of the path may be replaced by environment strings, such as %USERPROFILE%.

### `hToken` [in]

Type: **HANDLE**

An [access token](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens) that can be used to represent a particular user. This parameter is usually set to **NULL**, in which case the function tries to access the current user's instance of the folder. However, you may need to assign a value to *hToken* for those folders that can have multiple users but are treated as belonging to a single user. The most commonly used folder of this type is **Documents**.

The calling application is responsible for correct impersonation when *hToken* is non-null. It must have appropriate security privileges for the particular user, including TOKEN_QUERY and TOKEN_IMPERSONATE, and the user's registry hive must be currently mounted. See [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control) for further discussion of access control issues.

### `dwFlags` [in]

Type: **DWORD**

Reserved. Must be set to 0.

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the folder's new path. This value cannot be **NULL**, and the string cannot be of zero length.

## Return value

Type: **HRESULT**

Returns standard **HRESULT** codes, including the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The folder's path was successfully updated. |
| **E_INVALIDARG** | Several error conditions cause the return of this value, including the following:<br><br>* The *csidl* value is not valid.<br>* The *csidl* value does not refer to a virtual folder.<br>* The *csidl* value does not refer to a system folder.<br>* The *csidl* value refers to a folder that cannot be renamed or moved.<br>* The *dwFlags* value is not 0 (zero).<br>* The *pszPath* value is **NULL**.<br>* The string pointed to by *pszPath* value is an empty string ("") of length zero. |

## Remarks

**Note** As of Windows Vista, this function is merely a wrapper for [SHSetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shsetknownfolderpath). The CSIDL value is translated to its associated [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) and **SHSetKnownFolderPath** is called. New applications should use the known folder system rather than the older CSIDL system, which is supported only for backward compatibility.

**SHSetFolderPath** is not exported by name from Shell32.dll. To use the function, you must call [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) with ordinal 231 for **SHSetFolderPathA** (for ANSI strings) or ordinal 232 for **SHSetFolderPathW** (for Unicode strings) to obtain a function pointer.

It is recommended that the paths be expressed as Unicode strings because folder names might contain Unicode characters not expressible in ANSI.

> [!NOTE]
> The shlobj_core.h header defines SHSetFolderPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[IKnownFolder::SetPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfolder-setpath)