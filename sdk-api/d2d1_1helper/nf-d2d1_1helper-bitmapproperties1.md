# BitmapProperties1 function

## Description

Creates a [D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_properties1) structure.

## Parameters

### `bitmapOptions`

Type: **[D2D1_BITMAP_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_bitmap_options)**

A combination of [D2D1_BITMAP_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_bitmap_options)-typed values that specify how the bitmap can be used.

### `pixelFormat` [in]

Type: **const [D2D1_PIXEL_FORMAT](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d1_pixel_format)**

The bitmap's pixel format and alpha mode. The default value is a [D2D1_PIXEL_FORMAT](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d1_pixel_format) with a **format** of [DXGI_FORMAT_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) and an **alphaMode** of [D2D1_ALPHA_MODE_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-d2d1_alpha_mode). For more information about pixel formats, see [Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes).

### `dpiX`

Type: **FLOAT**

The horizontal dpi of the bitmap. The default value is 96.0f.

### `dpiY`

Type: **FLOAT**

The vertical dpi of the bitmap. The default value is 96.0f.

### `colorContext` [in]

Type: **[ID2D1ColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1colorcontext)***

An optional pointer to the [ID2D1ColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1colorcontext) interface for a color context to use with the bitmap. If you don't want to specify a color context, set this parameter to **NULL**.

## Return value

Type: **[D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_properties1)**

A [D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_properties1) structure that describes the bitmap.