# IShellLibrary::RemoveFolder

## Description

Removes a folder from the library.

## Parameters

### `psiLocation` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

An [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object that represents the folder to remove.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For convenience, [SHRemoveFolderPathFromLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shremovefolderpathfromlibrary) can be used in place of this method.

#### Examples

The following code example shows the helper function [SHRemoveFolderPathFromLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shremovefolderpathfromlibrary), which wraps this method.

```cpp
//
// from shobjidl.h
//
__inline HRESULT SHRemoveFolderPathFromLibrary(
    __in IShellLibrary *plib,
    __in PCWSTR pszFolderPath)
{
    PIDLIST_ABSOLUTE pidlFolder =
      SHSimpleIDListFromPath (pszFolderPath);
    HRESULT hr = pidlFolder ? S_OK : E_INVALIDARG;

    if (SUCCEEDED(hr))
    {
        IShellItem *psiFolder;
        hr = SHCreateItemFromIDList (
          pidlFolder,
          IID_PPV_ARGS(&psiFolder));

        if (SUCCEEDED(hr))
        {
            hr = plib->RemoveFolder(psiFolder);
            psiFolder->Release();
        }
        CoTaskMemFree(pidlFolder);
    }
    return hr;
}
```

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::AddFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-addfolder)

[IShellLibrary::LoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromitem)

[IShellLibrary::LoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromknownfolder)

[SHAddFolderPathToLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shaddfolderpathtolibrary)

[SHLoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromitem)

[SHLoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromknownfolder)

[SHLoadLibraryFromParsingName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromparsingname)

[SHRemoveFolderPathFromLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shremovefolderpathfromlibrary)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))