# SHCreateDirectory function

## Description

[**SHCreateDirectory** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Creates a new file system folder.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

A handle to a parent window. This parameter can be set to **NULL** if no user interface is displayed.

### `pszPath` [in]

Type: **PCWSTR**

A pointer to a null-terminated Unicode string that contains the fully qualified path of the directory. This string should have no more than MAX_PATH characters, including the terminating null character.

## Return value

Type: **int**

Returns **ERROR_SUCCESS** if successful. If the operation fails, other error codes can be returned, including those listed here. For values not specifically listed, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_BAD_PATHNAME** | The *pszPath* parameter was set to a relative path. |
| **ERROR_FILENAME_EXCED_RANGE** | The path pointed to by *pszPath* is too long. |
| **ERROR_FILE_EXISTS** | The directory exists. |
| **ERROR_ALREADY_EXISTS** | The directory exists. |
| **ERROR_CANCELLED** | The user canceled the operation. |

## Remarks

This function creates a file system folder whose fully qualified path is given by *pszPath*. If one or more of the intermediate folders do not exist, it creates them.

To set security attributes on a new folder, use [SHCreateDirectoryEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreatedirectoryexa).

## See also

[SHCreateDirectoryEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreatedirectoryexa)