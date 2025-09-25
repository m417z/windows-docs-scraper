# IShellLibrary::LoadLibraryFromItem

## Description

Loads the library from a specified library definition file.

## Parameters

### `psiLibrary` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

An [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object for the library definition file to load. An error is returned if this object is not a library.

### `grfMode` [in]

Type: **DWORD**

One or more [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) storage medium flags that specify access and sharing modes for the library object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this method is called on an [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object that is already loaded, the contents of that object are overwritten in memory with the new information.

If there is no existing library object, [SHLoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromitem) can be called in place of this method.

#### Examples

The following code example shows the helper function [SHLoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromitem), which wraps this method.

```cpp
//
// from shobjidl.h
//
__inline HRESULT SHLoadLibraryFromItem(
    __in IShellItem *psiLibrary,
    __in DWORD grfMode,
    __in REFIID riid,
    __deref_out void **ppv
)
{
    *ppv = NULL;
    IShellLibrary *plib;

    HRESULT hr = CoCreateInstance(
      CLSID_ShellLibrary,
      NULL,
      CLSCTX_INPROC_SERVER,
      IID_PPV_ARGS(&plib));

    if (SUCCEEDED(hr))
    {
        hr = plib->LoadLibraryFromItem (psiLibrary, grfMode);
        if (SUCCEEDED(hr))
        {
            hr = plib->QueryInterface (riid, ppv);
        }
        plib->Release();
    }
    return hr;
}

```

The following code example shows the helper function [SHLoadLibraryFromParsingName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromparsingname), which wraps this method.

```cpp
//
// from shobjidl.h
//
__inline HRESULT SHLoadLibraryFromParsingName(
    __in PCWSTR pszParsingName,
    __in DWORD grfMode,
    __in REFIID riid,
    __deref_out void **ppv
)
{
    *ppv = NULL;
    IShellItem *psiLibrary;
    HRESULT hr = SHCreateItemFromParsingName (
      pszParsingName,
      NULL,
      IID_PPV_ARGS(&psiLibrary));

    if (SUCCEEDED(hr))
    {
        hr = SHLoadLibraryFromItem (psiLibrary, grfMode, riid, ppv);
        psiLibrary->Release();
    }
    return hr;
}

```

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::LoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromknownfolder)

[Library Description Schema](https://learn.microsoft.com/windows/desktop/shell/library-schema-entry)

[SHLoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromitem)

[SHLoadLibraryFromParsingName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromparsingname)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))