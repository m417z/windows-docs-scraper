# GetFileNameFromBrowse function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Creates an **Open** dialog box so that the user can specify the drive, directory, and name of a file to open.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

A handle to the window that owns the dialog box. This member can be any valid window handle, or it can be **NULL** if the dialog box has no owner.

### `pszFilePath` [in, out]

Type: **PWSTR**

A null-terminated Unicode string that contains a file name used to initialize the File Name edit control. This string corresponds to the [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure's **lpstrFile** member and is used in exactly the same way.

### `cchFilePath`

Type: **UINT**

The number of characters in *pszFilePath*, including the terminating null character.

### `pszWorkingDir` [in, optional]

Type: **PCWSTR**

The fully qualified file path of the initial directory. This string corresponds to the [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure's **lpstrInitialDir** member and is used in exactly the same way.

### `pszDefExt` [in]

Type: **PCWSTR**

A null-terminated Unicode string that contains the default file name extension. This extension is added to *pszFilePath* if the user does not specify an extension. The string should not contain any '.' characters. If this string is **NULL** and the user fails to type an extension, no extension is appended.

### `pszFilters` [in, optional]

Type: **PCWSTR**

A null-terminated Unicode string that defines the filter. This string corresponds to the [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure's **lpstrFilter** member and is used in exactly the same way.

### `pszTitle` [in, optional]

Type: **PCWSTR**

A null-terminated Unicode string that is placed in the title bar of the dialog box. If this value is **NULL**, the system uses the default title.

## Return value

Type: **BOOL**

If the user specifies a file name and clicks **OK**, the return value is **TRUE**. The buffer that *pszFilePath* points to contains the full path and file name that the user specifies. If the user cancels or closes the **Open** dialog box or an error occurs, the return value is **FALSE**.

## See also

[GetOpenFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getopenfilenamea)