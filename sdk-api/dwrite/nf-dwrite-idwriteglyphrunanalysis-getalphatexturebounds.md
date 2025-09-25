# IDWriteGlyphRunAnalysis::GetAlphaTextureBounds

## Description

 Gets the bounding rectangle of the physical pixels affected by the glyph run.

## Parameters

### `textureType`

Type: **[DWRITE_TEXTURE_TYPE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_texture_type)**

Specifies the type of texture requested. If a bi-level texture is requested, the
bounding rectangle includes only bi-level glyphs. Otherwise, the bounding rectangle includes only antialiased
glyphs.

### `textureBounds` [out]

Type: **RECT***

When this method returns, contains the bounding rectangle of the physical pixels affected by the glyph run, or an empty rectangle if there are no glyphs
of the specified texture type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteGlyphRunAnalysis](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteglyphrunanalysis)