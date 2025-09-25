# IShellLibrary::SaveInKnownFolder

## Description

Saves the library to a new file in a specified known folder.

## Parameters

### `kfidToSaveIn` [in]

Type: **REFKNOWNFOLDERID**

The ID of the known folder in which to save the [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object.
For more information, see [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid).

### `pszLibraryName` [in]

Type: **LPCWSTR**

The file name under which to save the library. The file name must not include the file name extension; the file name extension is added automatically.

### `lsf` [in]

Type: **[LIBRARYSAVEFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-librarysaveflags)**

The [LIBRARYSAVEFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-librarysaveflags) value that specifies how to handle a library name collision.

### `ppsiSavedTo` [out]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)****

The [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object that represents the library description file into which the library was saved.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[IShellLibrary::Save](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-save) and [SHSaveLibraryInFolderPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shsavelibraryinfolderpath) create a new library file, and save the file to disk.
To save changes made to a library that has an existing library file, call [IShellLibrary::Commit](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-commit).

If the library is saved in the Libraries known folder (FOLDERID_Libraries), the library's location is automatically added to the system index.

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))

[Library Description Schema](https://learn.microsoft.com/windows/desktop/shell/library-schema-entry)

[SHSaveLibraryInFolderPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shsavelibraryinfolderpath)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))