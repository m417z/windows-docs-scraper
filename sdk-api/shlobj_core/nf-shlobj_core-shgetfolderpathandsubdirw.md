# SHGetFolderPathAndSubDirW function

## Description

Gets the path of a folder and appends a user-provided subfolder path.

## Parameters

### `hwnd` [in]

Type: **HWND**

Reserved.

### `csidl` [in]

Type: **int**

A [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value that identifies the folder whose path is to be retrieved. Only real folders are valid. If a virtual folder is specified, this function fails. You can force creation of a folder with **SHGetFolderPathAndSubDir** by combining the folder's **CSIDL** with CSIDL_FLAG_CREATE.

### `hToken` [in]

Type: **HANDLE**

An [access token](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens) that represents a particular user. For systems earlier than Windows 2000, set this value to **NULL**. For later systems, *hToken* is usually, but not always, set to **NULL**. You might need to assign a value to *hToken* for those folders that can have multiple users but are treated as belonging to a single user. The most commonly used folder of this type is [My Documents](https://learn.microsoft.com/windows/desktop/shell/manage).

### `dwFlags` [in]

Type: **DWORD**

Specifies whether the path to be returned is the actual path of the folder or the default path. This value is used in cases where the folder associated with a [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value may be moved or renamed by the user.

#### SHGFP_TYPE_CURRENT

Return the folder's current path.

#### SHGFP_TYPE_DEFAULT

Return the folder's default path.

### `pszSubDir` [in]

Type: **LPCTSTR**

A pointer to the subpath to be appended to the folder's path. This is a **null**-terminated string of length MAX_PATH. If you are not creating a new directory, this must be an existing subdirectory or the function returns an error. This value can be **NULL** if no subpath is to be appended.

### `pszPath` [out]

Type: **LPTSTR**

When this function returns, this value points to the directory path and appended subpath. This is a **null**-terminated string of length MAX_PATH. This string is empty when the function returns an error code.

##### - dwFlags.SHGFP_TYPE_CURRENT

Return the folder's current path.

##### - dwFlags.SHGFP_TYPE_DEFAULT

Return the folder's default path.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[SHGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha)

## Remarks

> [!NOTE]
> The shlobj_core.h header defines SHGetFolderPathAndSubDir as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).