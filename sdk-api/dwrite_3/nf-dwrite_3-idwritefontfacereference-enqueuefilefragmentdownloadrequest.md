# IDWriteFontFaceReference::EnqueueFileFragmentDownloadRequest

## Description

Adds a request to the font download queue ([IDWriteFontDownloadQueue](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontdownloadqueue)).

## Parameters

### `fileOffset`

Type: **UINT64**

Offset of the fragment from the beginning of the font file.

### `fragmentSize`

Type: **UINT64**

Size of the fragment in bytes.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)