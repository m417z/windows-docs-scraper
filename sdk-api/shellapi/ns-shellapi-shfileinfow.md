# SHFILEINFOW structure

## Description

Contains information about a file object.

## Members

### `hIcon`

Type: **HICON**

A handle to the icon that represents the file. You are responsible for destroying this handle with [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) when you no longer need it.

### `iIcon`

Type: **int**

The index of the icon image within the system image list.

### `dwAttributes`

Type: **DWORD**

An array of values that indicates the attributes of the file object. For information about these values, see the [IShellFolder::GetAttributesOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof) method.

### `szDisplayName`

Type: **TCHAR[MAX_PATH]**

A string that contains the name of the file as it appears in the Windows Shell, or the path and file name of the file that contains the icon representing the file.

### `szTypeName`

Type: **TCHAR[80]**

A string that describes the type of file.

## Remarks

This structure is used with the [SHGetFileInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetfileinfoa) function.

> [!NOTE]
> The shellapi.h header defines SHFILEINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).