# IDWriteFontFaceReference::EnqueueCharacterDownloadRequest

## Description

Adds a request to the font download queue ([IDWriteFontDownloadQueue](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontdownloadqueue)).

## Parameters

### `characters` [in]

Type: **const WCHAR***

Array of characters to download.

### `characterCount`

Type: **UINT32**

The number of elements in the character array.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 Downloading a character involves downloading every glyph it depends on directly or indirectly, via font tables (cmap, GSUB, COLR, glyf).

## See also

[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)