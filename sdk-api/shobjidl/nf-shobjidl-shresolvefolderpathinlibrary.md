# SHResolveFolderPathInLibrary function

## Description

Attempts to resolve the target location of a library folder that has been moved or renamed.

## Parameters

### `plib` [in]

Type: **[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)***

The [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object for which to resolve the target location.

### `pszFolderPath` [in]

Type: **PCWSTR**

The path of the library folder to locate.

### `dwTimeout` [in]

Type: **DWORD**

The maximum time, in milliseconds, that the method attempts to locate the folder before returning. If the folder could not be located before the specified time elapses, an error is returned.

### `ppszResolvedPath` [out]

Type: **PWSTR***

A pointer to a string that, when this function successfully returns, contains the current path of the library folder specified in *plib*.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is an inline helper function that wraps the [IShellLibrary::ResolveFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-resolvefolder) method.

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::ResolveFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-resolvefolder)