# IShellLibrary::Commit

## Description

Commits library updates to an existing Library Description file.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IShellLibrary::Commit** can only be called to save library updates to an existing file. A call to **IShellLibrary::Commit** for a library that does not have a backing file will fail.
To create and save a new file, call [IShellLibrary::Save](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-save) or [SHSaveLibraryInFolderPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shsavelibraryinfolderpath).

If the library is saved in the Libraries known folder (FOLDERID_Libraries), the folders in the library are automatically added to the search index.

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::Save](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-save)

[Library Description Schema](https://learn.microsoft.com/windows/desktop/shell/library-schema-entry)

[SHSaveLibraryInFolderPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shsavelibraryinfolderpath)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))