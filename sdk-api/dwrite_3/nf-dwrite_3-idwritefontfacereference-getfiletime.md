# IDWriteFontFaceReference::GetFileTime

## Description

Get the last modified date.

## Parameters

### `lastWriteTime` [out]

Type: **FILETIME***

Returns the last modified date. The time may be zero if the font file loader does not expose file time.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)