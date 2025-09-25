# SHRemoveFolderPathFromLibrary function

## Description

Removes a folder from a library.

## Parameters

### `plib` [in]

Type: **[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)***

The [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object from which to remove the folder.

### `pszFolderPath` [in]

Type: **PCWSTR**

The path of the folder to remove.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is an inline helper function that wraps the [IShellLibrary::RemoveFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-removefolder) method.

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::AddFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-addfolder)

[IShellLibrary::LoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromitem)

[IShellLibrary::LoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromknownfolder)

[IShellLibrary::RemoveFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-removefolder)

[SHAddFolderPathToLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shaddfolderpathtolibrary)

[SHLoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromitem)

[SHLoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromknownfolder)

[SHLoadLibraryFromParsingName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromparsingname)