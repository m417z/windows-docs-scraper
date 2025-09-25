# ID2D1DeviceContext4::GetSvgGlyphImage

## Description

Retrieves an image of the SVG glyph from the color glyph cache. If the cache does not already contain the requested resource, it will be created.
This method may be used to extend the lifetime of a glyph image even after it is evicted from the color glyph cache.

## Parameters

### `glyphOrigin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

Origin of the glyph.

### `fontFace` [in]

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/desktop/api/dwrite/nn-dwrite-idwritefontface)***

Reference to a font face which contains font face type, appropriate file references, face identification data and various font data such as metrics, names and glyph outlines.

### `fontEmSize`

Type: **FLOAT**

The specified font size affects the output
glyphTransform, causing it to properly scale the glyph.

### `glyphIndex`

Type: **UINT16**

Index of the glyph to retrieve.

### `isSideways`

Type: **BOOL**

If true, specifies that glyphs are rotated 90 degrees to the left and vertical metrics are used. Vertical writing is achieved by specifying isSideways as true and rotating the entire run 90 degrees to the right via a rotate transform.

### `worldTransform` [in, optional]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)***

The transform to apply to the image.

### `defaultFillBrush` [in, optional]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

Describes how the area is painted.

### `svgGlyphStyle` [in, optional]

Type: **[ID2D1SvgGlyphStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1svgglyphstyle)***

The values for context-fill, context-stroke, and context-value that are used when rendering SVG glyphs.

### `colorPaletteIndex`

Type: **UINT32**

The index used to select a color palette within a color font.
Note that this not the same as the paletteIndex in the DWRITE_COLOR_GLYPH_RUN struct, which is not relevant for SVG glyphs.

### `glyphTransform` [out]

Type: **[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)***

Output transform, which transforms from the glyph's space to the same output space as the worldTransform.
This includes the input glyphOrigin, the glyph's offset from the glyphOrigin, and any other required transformations.

### `glyphImage` [out]

Type: **[ID2D1CommandList](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandlist)****

On completion, contains the retrieved glyph image.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1DeviceContext4](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext4)