# SHSaveLibraryInFolderPath function

## Description

Saves an [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object to disk.

## Parameters

### `plib` [in]

Type: **[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)***

A pointer to the [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object to save.

### `pszFolderPath` [in]

Type: **PCWSTR**

A pointer to the path to the folder in which to save the library.

### `pszLibraryName` [in]

Type: **PCWSTR**

A pointer to a file name under which to save the library. The file name must not include the file name extension. The file name extension is added automatically.

### `lsf` [in]

Type: **[LIBRARYSAVEFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-librarysaveflags)**

A value from the [LIBRARYSAVEFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-librarysaveflags) enumeration that specifies how to handle a library name collision.

### `ppszSavedToPath` [out, optional]

Type: **PWSTR***

A pointer to a string that, when this function returns successfully, receives the path to the library description file into which the library was saved. If this path is not required, the value of this parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is an inline helper function that wraps the [IShellLibrary::Save](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-save) method.

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::Save](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-save)

[IShellLibrary::SaveInKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-saveinknownfolder)