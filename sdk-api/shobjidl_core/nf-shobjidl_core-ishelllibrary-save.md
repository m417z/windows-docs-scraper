# IShellLibrary::Save

## Description

Saves the library to a new Library Description (*.library-ms) file.

## Parameters

### `psiFolderToSaveIn` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

The [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object that specifies the folder in which to save the library, or **NULL** to save the library with the user's default libraries in the FOLDERID_Libraries known folder.

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

**IShellLibrary::Save** and [SHSaveLibraryInFolderPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shsavelibraryinfolderpath) create a new library file, and save the file to disk. To save changes made to a library that has an existing library file, call [IShellLibrary::Commit](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-commit).

If the library is saved in the Libraries known folder (FOLDERID_Libraries), the library's location is automatically added to the system index.

For convenience, [SHSaveLibraryInFolderPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shsavelibraryinfolderpath) can be used in place of this method.

#### Examples

The following code example shows the helper function [SHSaveLibraryInFolderPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shsavelibraryinfolderpath), which wraps this method.

```cpp
//
// from shobjidl.h
//
__inline HRESULT SHSaveLibraryInFolderPath(
    __in IShellLibrary *plib,
    __in PCWSTR pszFolderPath,
    __in PCWSTR pszLibraryName,
    __in LIBRARYSAVEFLAGS lsf,
    __deref_opt_out PWSTR *ppszSavedToPath
)
{
    if (ppszSavedToPath)
    {
        *ppszSavedToPath = NULL;
    }

    IShellItem *psiFolder;
    HRESULT hr = SHCreateItemFromParsingName(
      pszFolderPath,
      NULL,
      IID_PPV_ARGS(&psiFolder));

    if (SUCCEEDED(hr))
    {
        IShellItem *psiSavedTo;
        hr = plib->Save(psiFolder, pszLibraryName, lsf, &psiSavedTo);

        if (SUCCEEDED(hr))
        {
            if (ppszSavedToPath)
            {
                hr = psiSavedTo->GetDisplayName(
                  SIGDN_DESKTOPABSOLUTEPARSING,
                  ppszSavedToPath);
            }
            psiSavedTo->Release();
        }
        psiFolder->Release();
    }
    return hr;
}
```

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[SHSaveLibraryInFolderPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shsavelibraryinfolderpath)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))