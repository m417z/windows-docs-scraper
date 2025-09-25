# IShellLibrary::LoadLibraryFromKnownFolder

## Description

Loads the library that is referenced by a KNOWNFOLDERID.

## Parameters

### `kfidLibrary` [in]

Type: **REFKNOWNFOLDERID**

The [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) value that identifies the library to load.

### `grfMode` [in]

Type: **DWORD**

One or more [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) storage medium flags that specify access and sharing modes for the library object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object contains a library when this method is called, that library is overwritten in memory with the new library.

If there is no existing [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object for this library, [SHLoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromitem) can be called in place of this method.

#### Examples

The following code example shows the helper function [SHLoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromknownfolder), which wraps this method.

```cpp
//
// from shobjidl.h
//
__inline HRESULT SHLoadLibraryFromKnownFolder(
    __in REFKNOWNFOLDERID kfidLibrary,
    __in DWORD grfMode,
    __in REFIID riid,
    __deref_out void **ppv)
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
        hr = plib->LoadLibraryFromKnownFolder(kfidLibrary, grfMode);
        if (SUCCEEDED(hr))
        {
            hr = plib->QueryInterface(riid, ppv);
        }
        plib->Release();
    }
    return hr;}
```

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::LoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromitem)

[SHCreateLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreatelibrary)

[SHLoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromitem)

[SHLoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromknownfolder)

[SHLoadLibraryFromParsingName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromparsingname)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))