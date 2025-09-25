# SHGetSpecialFolderPathA function

## Description

[**SHGetSpecialFolderPath** is not supported. Instead, use [SHGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha).]

Retrieves the path of a special folder, identified by its [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl).

## Parameters

### `hwnd`

Type: **HWND**

Reserved.

### `pszPath` [out]

Type: **LPTSTR**

A pointer to a null-terminated string that receives the drive and path of the specified folder. This buffer must be at least MAX_PATH characters in size.

### `csidl` [in]

Type: **int**

A [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) that identifies the folder of interest. If a virtual folder is specified, this function will fail.

### `fCreate` [in]

Type: **BOOL**

Indicates whether the folder should be created if it does not already exist. If this value is nonzero, the folder is created. If this value is zero, the folder is not created.

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise, **FALSE**.

## Remarks

The Microsoft Internet Explorer 4.0 Desktop Update must be installed for this function to be available.

> [!NOTE]
> The shlobj_core.h header defines SHGetSpecialFolderPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).