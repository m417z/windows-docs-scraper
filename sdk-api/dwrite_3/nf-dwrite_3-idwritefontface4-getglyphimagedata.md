# IDWriteFontFace4::GetGlyphImageData

## Description

Gets a pointer to the glyph data based on the desired image format.

## Parameters

### `glyphId` [in]

Type: **UINT16**

The ID of the glyph to retrieve image data for.

### `pixelsPerEm`

Type: **UINT32**

Requested pixels per em.

### `glyphImageFormat`

Type: **[DWRITE_GLYPH_IMAGE_FORMATS](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_glyph_image_formats)**

Specifies which formats are supported in the font.

### `glyphData` [out]

Type: **[DWRITE_GLYPH_IMAGE_DATA](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_glyph_image_data)***

On return contains data for a glyph.

### `glyphDataContext` [out]

Type: **void****

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

The glyphDataContext must be released via [ReleaseGlyphImageData](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontface4-releaseglyphimagedata) when done if the data is not empty,
similar to [IDWriteFontFileStream::ReadFileFragment](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontfilestream-readfilefragment)
and [IDWriteFontFileStream::ReleaseFileFragment](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefontfilestream-releasefilefragment).
The data pointer is valid so long as the [IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface) exists and **ReleaseGlyphImageData** has not
been called.

The [DWRITE_GLYPH_IMAGE_DATA::uniqueDataId](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_glyph_image_data) is valuable for caching purposes so that if the same
resource is returned more than once, an existing resource can be quickly retrieved rather than
needing to reparse or decompress the data.

The function only returns SVG or raster data - requesting TrueType/CFF/COLR data returns
DWRITE_E_INVALIDARG. Those must be drawn via DrawGlyphRun or queried using GetGlyphOutline instead.
Exactly one format may be requested or else the function returns DWRITE_E_INVALIDARG.
If the glyph does not have that format, the call is not an error, but the function returns empty data.

## See also

[IDWriteFontFace4](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface4)