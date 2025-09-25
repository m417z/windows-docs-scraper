# ICDBurn::Burn

## Description

Instructs data to be copied from the staging area to a writable CD.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the parent window of the UI.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *staging area* has a default location of %userprofile%\Local Settings\Application Data\Microsoft\CD Burning. Its actual path can be retrieved through [SHGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha), [SHGetSpecialFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetspecialfolderpatha), [SHGetFolderLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderlocation), [SHGetSpecialFolderLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetspecialfolderlocation), or [SHGetFolderPathAndSubDir](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpathandsubdira) by using the CSIDL_CDBURN_AREA value.