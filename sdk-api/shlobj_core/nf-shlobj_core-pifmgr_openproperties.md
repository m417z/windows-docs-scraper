# PifMgr_OpenProperties function

## Description

[**PifMgr_OpenProperties** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Opens the .pif file associated with a Microsoft MS-DOS application, and returns a handle to the application's properties.

## Parameters

### `pszApp` [in]

Type: **PCWSTR**

A null-terminated Unicode string that contains the application's name.

### `pszPIF` [in, optional]

Type: **PCWSTR**

A null-terminated Unicode string that contains the name of the .pif file.

### `hInf`

Type: **UINT**

A handle to the application's .inf file. Set this value to zero if there is no .inf file. Set this value to -1 to prevent the .inf file from being processed.

### `flOpt`

Type: **UINT**

A flag that controls how the function operates.

#### OPENPROPS_INHIBITPIF

Ignore any existing .pif files and get the properties from win.ini or _Default.pif. This flag is ignored on Windows NT, Windows 2000, and Windows XP.

#### OPENPROPS_NONE

No options specified.

## Return value

Type: **HANDLE**

Returns a handle to the application's properties. Use this handle when you call the related .pif functions.

## Remarks

You should not think of **PifMgr_OpenProperties** as a function that opens a file somewhere. The .pif file does not remain open after this call. It is more useful to think of the function as a property structure allocator that you can initialize using disk data.
The primary reason why this function fails is because of low memory or inability to open the specified .pif file.

If no .pif file exists, the function still allocates a data block in memory and initializes it with data from _Default.pif or its internal defaults. If the function looks for a .pif file name but does not find it, it constructs a name and saves it in its internal .pif data structure. This guarantees that if [PifMgr_SetProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_setproperties) is called, the data is saved to disk.

If the function does not find the .pif file, it searches for it in the following order.

1. Searches the current directory.
2. Searches the specified directory.
3. Searches in .pif directory.
4. Searches the folders specified by the PATH environment variable.

## See also

[PifMgr_CloseProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_closeproperties)

[PifMgr_GetProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_getproperties)