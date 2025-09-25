# LIBRARYSAVEFLAGS enumeration

## Description

Specifies the options for handling a name collision when saving a library.

## Constants

### `LSF_FAILIFTHERE:0`

If a library with the same name already exists, the save operation fails.

### `LSF_OVERRIDEEXISTING:0x1`

If a library with the same name already exists, the save operation overwrites the existing library.

### `LSF_MAKEUNIQUENAME:0x2`

If a library with the same name already exists, the save operation generates a new, unique name for the library.

## Remarks

### Used By

* [IShellLibrary::Save](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-save)
* [IShellLibrary::SaveInKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-saveinknownfolder)
* [SHSaveLibraryInFolderPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shsavelibraryinfolderpath)

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)