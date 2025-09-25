# IDWriteFontFace4::GetGlyphImageFormats(UINT16,UINT32,UINT32,DWRITE_GLYPH_IMAGE_FORMATS)

## Description

Gets all the glyph image formats supported for the specified glyph.

## Parameters

### `glyphId`

The identifier of the glyph to be queried.

### `pixelsPerEmFirst`

The lowest pixels per em value to query.

### `pixelsPerEmLast`

The highest pixels per em value to query.

### `glyphImageFormats`

An array of [DWRITE_GLYPH_IMAGE_FORMATS](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-dwrite_glyph_image_formats) specifying the supported formats for the requested glyph.

## Return value

HRESULT

Type: **[DWRITE_GLYPH_IMAGE_FORMATS](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_glyph_image_formats)**

## See also

[IDWriteFontFace4](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface4)