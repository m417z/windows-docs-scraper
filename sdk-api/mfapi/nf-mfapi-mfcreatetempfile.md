# MFCreateTempFile function

## Description

Creates a byte stream that is backed by a temporary local file.

## Parameters

### `AccessMode`

The requested access mode, specified as a member of the [MF_FILE_ACCESSMODE](https://learn.microsoft.com/windows/win32/api/mfobjects/ne-mfobjects-mf_file_accessmode) enumeration.

### `OpenMode`

The behavior of the function if the file already exists or does not exist, specified as a member of the [MF_FILE_OPENMODE](https://learn.microsoft.com/windows/win32/api/mfobjects/ne-mfobjects-mf_file_openmode) enumeration.

### `fFlags`

Bitwise **OR** of values from the [MF_FILE_FLAGS](https://learn.microsoft.com/windows/win32/api/mfobjects/ne-mfobjects-mf_file_flags) enumeration.

### `ppIByteStream`

Receives a pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of the byte stream. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function creates a file in the system temporary folder, and then returns a byte stream object for that file.
The full path name of the file is stored in the [MF_BYTESTREAM_ORIGIN_NAME](https://learn.microsoft.com/windows/desktop/medfound/mf-bytestream-origin-name-attribute) attribute. The file is created with the **FILE_FLAG_DELETE_ON_CLOSE** flag, and is deleted after the byte stream is released.

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)