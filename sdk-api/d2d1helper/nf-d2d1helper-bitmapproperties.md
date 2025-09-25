# BitmapProperties function

## Description

Creates a [D2D1_BITMAP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_bitmap_properties) structure.

## Parameters

### `pixelFormat` [ref]

Type: **const [D2D1_PIXEL_FORMAT](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d1_pixel_format)**

The bitmap's pixel format and alpha mode. The default value is a [D2D1_PIXEL_FORMAT](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d1_pixel_format) with a **format** of [DXGI_FORMAT_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) and an **alphaMode** of [D2D1_ALPHA_MODE_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-d2d1_alpha_mode). For more information about pixel formats, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes).

### `dpiX`

Type: **FLOAT**

The horizontal dpi of the bitmap. The default value is 96.0f.

### `dpiY`

Type: **FLOAT**

The vertical dpi of the bitmap. The default value is 96.0f.

## Return value

Type: **[D2D1_BITMAP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_bitmap_properties)**

A structure that describes the pixel format and dpi
of a bitmap.

## See also

[ID2D1Bitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1bitmap)