# D2D1_BITMAP_PROPERTIES1 structure

## Description

This structure allows a [ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1) to be created with bitmap options and color context information available.

## Members

### `pixelFormat`

Type: **[D2D1_PIXEL_FORMAT](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d1_pixel_format)**

The DXGI format and alpha mode to create the bitmap with.

### `dpiX`

Type: **FLOAT**

The bitmap dpi in the x direction.

### `dpiY`

Type: **FLOAT**

The bitmap dpi in the y direction.

### `bitmapOptions`

Type: **[D2D1_BITMAP_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_bitmap_options)**

The special creation options of the bitmap.

### `colorContext`

Type: **[ID2D1ColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1colorcontext)***

The optionally specified color context information.

## Remarks

If both **dpiX** and **dpiY** are 0, the dpi of the bitmap will be set to the desktop dpi if the device context is a windowed context, or 96 dpi for any other device context.

## See also

[ID2D1DeviceContext::CreateBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmap(d2d1_size_u_constvoid_uint32_constd2d1_bitmap_properties1_id2d1bitmap1))