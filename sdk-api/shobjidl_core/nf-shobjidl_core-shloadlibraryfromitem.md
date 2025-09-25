# SHLoadLibraryFromItem function

## Description

Creates and loads an [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object from a specified library definition file.

## Parameters

### `psiLibrary` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

An [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object for the library definition file to load.

### `grfMode` [in]

Type: **DWORD**

One or more storage medium flags that specify access and sharing modes for the library object. Commonly specified flags are **STGM_READ** or **STGM_READWRITE**. For more information, see [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants).

### `riid` [in]

Type: **REFIID**

The IID for [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary). (See usage remarks.)

### `ppv` [out]

Type: **void****

Receives the loaded [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object. (See usage remarks.)

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

### Usage

The **IID_PPV_ARGS** macro is generally used to generate the *riid* and *ppv* parameters for this function. For an example, see [SHCreateLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreatelibrary).

This is an inline helper function that wraps the [IShellLibrary::LoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromitem) method.

## See also

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::LoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromitem)

[IShellLibrary::LoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromknownfolder)

[SHCreateItemWithParent](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateitemwithparent)

[SHCreateLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreatelibrary)

[SHGetItemFromObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shgetitemfromobject)

[SHLoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromknownfolder)

[SHLoadLibraryFromParsingName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromparsingname)