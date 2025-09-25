# IShellLibrary::ResolveFolder

## Description

Resolves the target location of a library folder, even if the folder has been moved or renamed.

## Parameters

### `psiFolderToResolve` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

An [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object that represents the library folder to locate.

### `dwTimeout` [in]

Type: **DWORD**

The maximum time, in milliseconds, the method will attempt to locate the folder before returning. If the folder could not be located before the specified time elapses, an error is returned.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to get in *ppv* that will represent the resolved target location. This value is typically IID_IShellItem, but it can also be IID_IShellItem2 or the IID of any other interface that is implemented by CShellItem.

### `ppv` [out]

Type: **void****

A pointer to the interface requested in *riid*.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The target folder was located and returned in *ppv*; however, the library has been updated so [IShellLibrary::Commit](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-commit) or [IShellLibrary::Save](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-save) should be called to persist these changes. |
| **S_FALSE** | The target folder was located and returned in *ppv*. |
| **E_** | This method can return other error values. |

## Remarks

This method is a blocking call that can block the calling thread as long as the time specified in the *dwTimeout* parameter before returning. Because it blocks the thread from which it is called, it should not be called from a thread that also handles user interface interactions.

This method will not prompt the user to manually locate the folder if it cannot resolve the location.

For convenience, [SHResolveFolderPathInLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-shresolvefolderpathinlibrary) can be used in place of this method.

It is recommended that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error.

#### Examples

The following code example shows the helper function [SHResolveFolderPathInLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-shresolvefolderpathinlibrary), which wraps this method.

```cpp
//
// from shobjidl.h
//
__inline HRESULT SHResolveFolderPathInLibrary(
    __in IShellLibrary *plib,
    __in PCWSTR pszFolderPath,
    __in DWORD dwTimeout,
    __deref_out PWSTR *ppszResolvedPath
)
{
    *ppszResolvedPath = NULL;
    PIDLIST_ABSOLUTE pidlFolder =
      SHSimpleIDListFromPath(pszFolderPath);
    HRESULT hr = pidlFolder ? S_OK : E_INVALIDARG;
    if (SUCCEEDED(hr))
    {
        IShellItem *psiFolder;
        hr = SHCreateItemFromIDList(
          pidlFolder,
          IID_PPV_ARGS(&psiFolder));

        if (SUCCEEDED(hr))
        {
            IShellItem *psiResolved;
            hr = plib->ResolveFolder(
              psiFolder,
              dwTimeout,
              IID_PPV_ARGS(&psiResolved));

            if (SUCCEEDED(hr))
            {
                hr = psiResolved->GetDisplayName(
                  SIGDN_DESKTOPABSOLUTEPARSING,
                  ppszResolvedPath);
                psiResolved->Release();
            }
            psiFolder->Release();
        }
        CoTaskMemFree(pidlFolder);
    }
    return hr;
}
```

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::Commit](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-commit)

[IShellLibrary::Save](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-save)

[SHResolveFolderPathInLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-shresolvefolderpathinlibrary)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))