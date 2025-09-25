# ID2D1DeviceContext4::DrawColorBitmapGlyphRun

## Description

Draws a color bitmap glyph run using one of the bitmap formats.

## Parameters

### `glyphImageFormat`

Type: **[DWRITE_GLYPH_IMAGE_FORMATS](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-dwrite_glyph_image_formats)**

Specifies the format of the glyph image. Supported formats are DWRITE_GLYPH_IMAGE_FORMATS_PNG, DWRITE_GLYPH_IMAGE_FORMATS_JPEG,
DWRITE_GLYPH_IMAGE_FORMATS_TIFF, or DWRITE_GLYPH_IMAGE_FORMATS_PREMULTIPLIED_B8G8R8A8. This method will result in an error if the color glyph run does not contain the requested format.

Only one format can be specified at a time, combinations of flags are not valid input.

### `baselineOrigin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The origin of the baseline for the glyph run.

### `glyphRun` [in]

Type: **const [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/desktop/api/dwrite/ns-dwrite-dwrite_glyph_run)***

The glyphs to render.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

Indicates the measuring method.

### `bitmapSnapOption`

Type: **[D2D1_COLOR_BITMAP_GLYPH_SNAP_OPTION](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ne-d2d1_3-d2d1_color_bitmap_glyph_snap_option)**

Specifies the pixel snapping policy when rendering color bitmap glyphs.

## See also

[ID2D1DeviceContext4](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext4)