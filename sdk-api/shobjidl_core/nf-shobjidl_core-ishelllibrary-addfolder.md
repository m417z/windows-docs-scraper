# IShellLibrary::AddFolder

## Description

Adds a folder to the library.

## Parameters

### `psiLocation` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

An [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object that represents the folder to be added to the library.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a folder is added to a library it is also added to the [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) index.

For convenience, [SHAddFolderPathToLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shaddfolderpathtolibrary) can be used in place of this method.

#### Examples

The following code example shows the helper function [SHAddFolderPathToLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shaddfolderpathtolibrary), which wraps this method.

```cpp
//
// From Shobjidl.h
//
__inline HRESULT SHAddFolderPathToLibrary (
    __in IShellLibrary *plib,
    __in PCWSTR pszFolderPath
)
{
    IShellItem *psiFolder;

    HRESULT hr = SHCreateItemFromParsingName (
      pszFolderPath,
      NULL,
      IID_PPV_ARGS(&psiFolder));

    if (SUCCEEDED(hr))
    {
        hr = plib->AddFolder (psiFolder);
        psiFolder->Release ();
    }
    return hr;
}
```

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::LoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromitem)

[IShellLibrary::LoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromknownfolder)

[IShellLibrary::RemoveFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-removefolder)

[Library Description Schema](https://learn.microsoft.com/windows/desktop/shell/library-schema-entry)

[SHAddFolderPathToLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shaddfolderpathtolibrary)

[SHLoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromitem)

[SHLoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromknownfolder)

[SHLoadLibraryFromParsingName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromparsingname)

[SHRemoveFolderPathFromLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shremovefolderpathfromlibrary)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))