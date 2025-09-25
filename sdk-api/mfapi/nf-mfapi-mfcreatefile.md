# MFCreateFile function

## Description

Creates a byte stream from a file.

## Parameters

### `AccessMode`

The requested access mode, specified as a member of the [MF_FILE_ACCESSMODE](https://learn.microsoft.com/windows/win32/api/mfobjects/ne-mfobjects-mf_file_accessmode) enumeration.

### `OpenMode`

The behavior of the function if the file already exists or does not exist, specified as a member of the [MF_FILE_OPENMODE](https://learn.microsoft.com/windows/win32/api/mfobjects/ne-mfobjects-mf_file_openmode) enumeration.

### `fFlags`

Bitwise **OR** of values from the [MF_FILE_FLAGS](https://learn.microsoft.com/windows/win32/api/mfobjects/ne-mfobjects-mf_file_flags) enumeration.

### `pwszFileURL`

Pointer to a null-terminated string that contains the file name.

### `ppIByteStream`

Receives a pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of the byte stream. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)