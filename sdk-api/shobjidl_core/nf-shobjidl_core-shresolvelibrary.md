# SHResolveLibrary function

## Description

Resolves all locations in a library, even those locations that have been moved or renamed.

## Parameters

### `psiLibrary` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object that represents the library.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function can block the calling thread for as long as it takes to resolve all the locations in the specified library. Because it blocks the thread from which it is called, it should not be called from a thread that also handles user interface interactions.

This function resolves all locations in the specified library in a single call. To resolve an individual location in a library, see the [IShellLibrary::ResolveFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-resolvefolder) method or the [SHResolveFolderPathInLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-shresolvefolderpathinlibrary) function.

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::ResolveFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-resolvefolder)