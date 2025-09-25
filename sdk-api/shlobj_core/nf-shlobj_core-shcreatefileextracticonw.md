# SHCreateFileExtractIconW function

## Description

[**SHCreateFileExtractIcon** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Creates a default [IExtractIcon](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iextracticona) handler for a file system object. Namespace extensions that display file system objects typically use this function. The extension and file attributes derive all that is needed for a simple icon extractor.

## Parameters

### `pszFile` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that specifies the file system object. The buffer must not exceed MAX_PATH characters in length.

### `dwFileAttributes` [in]

Type: **DWORD**

A combination of one or more file attribute flags (FILE_ATTRIBUTE_* values as defined in Winnt.h) that specify the type of object.

### `riid` [in]

Type: **REFIID**

Reference to the desired interface ID of the icon extractor interface to create. This must be either IID_IExtractIconA or IID_IExtractIconW.

### `ppv`

Type: **void****

When this function returns, contains the interface pointer requested in *riid*. This is typically [IExtractIcon](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iextracticona).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.