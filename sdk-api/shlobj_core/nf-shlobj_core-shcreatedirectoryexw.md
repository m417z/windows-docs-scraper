# SHCreateDirectoryExW function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Creates a new file system folder, with optional security attributes.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

A handle to a parent window. This parameter can be set to **NULL** if no user interface will be displayed.

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string specifying the fully qualified path of the directory. This string is of maximum length of 248 characters, including the terminating null character.

### `psa` [in, optional]

Type: **const [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)***

 A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure with the directory's security attribute. Set this parameter to **NULL** if no security attributes need to be set.

## Return value

Type: **int**

Returns **ERROR_SUCCESS** if successful. If the operation fails, other error codes can be returned, including those listed here. For values not specifically listed, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_BAD_PATHNAME** | The *pszPath* parameter was set to a relative path. |
| **ERROR_FILENAME_EXCED_RANGE** | The path pointed to by *pszPath* is too long. |
| **ERROR_PATH_NOT_FOUND** | The system cannot find the path pointed to by *pszPath*. The path may contain an invalid entry. |
| **ERROR_FILE_EXISTS** | The directory exists. |
| **ERROR_ALREADY_EXISTS** | The directory exists. |
| **ERROR_CANCELLED** | The user canceled the operation. |

## Remarks

This function creates a file system folder whose fully qualified path is given by *pszPath*. If one or more of the intermediate folders do not exist, they are created as well. **SHCreateDirectoryEx** also verifies that the files are visible. If they are not visible, expect one of the following:

* If *hwnd* is set to a valid window handle, a message box is displayed warning the user that he or she might not be able to access the files. If the user chooses not to proceed, the function returns **ERROR_CANCELLED**.
* If *hwnd* is set to **NULL**, no user interface is displayed and the function returns **ERROR_CANCELLED**.

> [!NOTE]
> The shlobj_core.h header defines SHCreateDirectoryEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SHCreateDirectory](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreatedirectory)