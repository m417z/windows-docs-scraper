# IDWriteRemoteFontFileStream::GetLocalFileSize

## Description

GetLocalFileSize returns the number of bytes of the font file that are currently local, which should always be less than or equal to the full
file size returned by [GetFileSize](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontfilestream-getfilesize).
If the locality is remote, the return value is zero. If the file is fully local, the return value must be the
same as [GetFileSize](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontfilestream-getfilesize).

## Parameters

### `localFileSize` [out]

Type: **UINT64***

Receives the local size of the file.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[IDWriteRemoteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriteremotefontfilestream)