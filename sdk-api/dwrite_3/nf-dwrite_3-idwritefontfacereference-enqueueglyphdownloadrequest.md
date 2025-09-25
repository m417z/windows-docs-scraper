# IDWriteFontFaceReference::EnqueueGlyphDownloadRequest

## Description

Adds a request to the font download queue ([IDWriteFontDownloadQueue](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontdownloadqueue)).

## Parameters

### `glyphIndices` [in]

Type: **const UINT16***

Array of glyph indices to download.

### `glyphCount`

Type: **UINT32**

The number of elements in the glyph index array.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Downloading a glyph involves downloading any other glyphs it depends on from the font tables (GSUB, COLR, glyf).

## See also

[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)