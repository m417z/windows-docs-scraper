# ID2D1DeviceContext4::GetColorBitmapGlyphImage

## Description

Retrieves an image of the color bitmap glyph from the color glyph cache. If the
cache does not already contain the requested resource, it will be created. This
method may be used to extend the lifetime of a glyph image even after it is
evicted from the color glyph cache.

## Parameters

### `glyphImageFormat`

Type: **[DWRITE_GLYPH_IMAGE_FORMATS](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-dwrite_glyph_image_formats)**

The format for the glyph image.
If there is no image data in the requested format for the requested glyph, this method will return an error.

### `glyphOrigin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The origin for the glyph.

### `fontFace` [in]

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/desktop/api/dwrite/nn-dwrite-idwritefontface)***

Reference to a font face which contains font face type, appropriate file references, face identification data and various font data such as metrics, names and glyph outlines.

### `fontEmSize`

Type: **FLOAT**

The specified font size affects the choice of which bitmap to use from the font. It also affects the output glyphTransform, causing it to properly scale the glyph.

### `glyphIndex`

Type: **UINT16**

Index of the glyph.

### `isSideways`

Type: **BOOL**

If true, specifies that glyphs are rotated 90 degrees to the left and vertical metrics are used. Vertical writing is achieved by specifying isSideways as true and rotating the entire run 90 degrees to the right via a rotate transform.

### `worldTransform` [in, optional]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)***

The transform to apply to the image. This input transform affects the choice of which bitmap to use from the font. It is also factored into the output glyphTransform.

### `dpiX`

Type: **FLOAT**

Dots per inch along the x-axis.

### `dpiY`

Type: **FLOAT**

Dots per inch along the y-axis.

### `glyphTransform` [out]

Type: **[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)***

Output transform, which transforms from the glyph's space to the same output space as the worldTransform. This includes the input
glyphOrigin, the glyph's offset from the glyphOrigin, and any other required transformations.

### `glyphImage` [out]

Type: **[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)****

On completion contains the retrieved glyph image.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1DeviceContext4](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext4)