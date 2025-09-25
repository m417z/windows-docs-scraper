# SHLoadLibraryFromKnownFolder function

## Description

Creates and loads an [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object for a specified known folder ID.

## Parameters

### `kfidLibrary` [in]

Type: **REFKNOWNFOLDERID**

The [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) value that identifies the known folder to load into the [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object.

### `grfMode` [in]

Type: **DWORD**

One or more storage medium flags that specify access and sharing modes for the library object. Commonly specified flags are **STGM_READ** or **STGM_READWRITE**. For more information, see [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants).

### `riid` [in]

Type: **REFIID**

The IID for [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary). (See Remarks for more information.)

### `ppv` [out]

Type: **void****

When this function returns successfully, receives the loaded [IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary) object. (See Remarks for more information.)

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is an inline helper function that wraps the [IShellLibrary::LoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromknownfolder) method.

### Usage

The **IID_PPV_ARGS** macro is generally used to generate the *riid* and *ppv* parameters for this function. For an example, see [SHCreateLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreatelibrary).

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::LoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromitem)

[IShellLibrary::LoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromknownfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))

[SHCreateLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreatelibrary)

[SHLoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromitem)

[SHLoadLibraryFromParsingName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromparsingname)