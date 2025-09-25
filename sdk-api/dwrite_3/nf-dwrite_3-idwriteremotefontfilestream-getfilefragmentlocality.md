# IDWriteRemoteFontFileStream::GetFileFragmentLocality

## Description

Returns information about the locality of a byte range (i.e., font fragment) within the font file stream.

## Parameters

### `fileOffset`

Type: **UINT64**

Offset of the fragment from the beginning of the font file.

### `fragmentSize`

Type: **UINT64**

Size of the fragment in bytes.

### `isLocal` [out]

Type: **BOOL***

Receives TRUE if the first byte of the fragment is local, FALSE if not.

### `partialSize`

Type: **UINT64***

Receives the number of contiguous bytes from the start of the fragment that have the same locality as the first byte.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[IDWriteRemoteFontFileStream](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriteremotefontfilestream)