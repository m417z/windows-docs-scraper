# D2D1_BITMAPSOURCE_PROP enumeration

## Description

Identifiers for properties of the [Bitmap source effect](https://learn.microsoft.com/windows/desktop/Direct2D/bitmap-source).

## Constants

### `D2D1_BITMAPSOURCE_PROP_WIC_BITMAP_SOURCE:0`

The IWICBitmapSource containing the image data to be loaded.

The type is IWICBitmapSource.

The default value is NULL.

### `D2D1_BITMAPSOURCE_PROP_SCALE:1`

The scale amount in the X and Y direction. The effect multiplies the width by the X value and the height by the Y value.
This property is a D2D1_VECTOR_2F defined as: (X scale, Y scale). The scale amounts are FLOAT, unitless, and must be positive or 0.

The type is D2D1_VECTOR_2F.

The default value is {1.0f, 1.0f}.

### `D2D1_BITMAPSOURCE_PROP_INTERPOLATION_MODE:2`

The interpolation mode used to scale the image.
If the mode disables the mipmap, then BitmapSouce will cache the image at the resolution determined by the Scale and EnableDPICorrection properties.

The type is [D2D1_BITMAPSOURCE_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_bitmapsource_interpolation_mode).

The default value is D2D1_BITMAPSOURCE_INTERPOLATION_MODE_LINEAR.

### `D2D1_BITMAPSOURCE_PROP_ENABLE_DPI_CORRECTION:3`

If you set this to TRUE, the effect will scale the input image to convert the DPI reported by IWICBitmapSource to the DPI of the device context.
The effect uses the interpolation mode you set with the InterpolationMode property. If you set this to FALSE, the effect uses a DPI of 96.0 for the output image.

The type is BOOL.

The default value is FALSE.

### `D2D1_BITMAPSOURCE_PROP_ALPHA_MODE:4`

The alpha mode of the output. This can be either premultiplied or straight.

The type is [D2D1_BITMAPSOURCE_ALPHA_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_bitmapsource_alpha_mode).

The default value is D2D1_BITMAPSOURCE_ALPHA_MODE_PREMULTIPLIED.

### `D2D1_BITMAPSOURCE_PROP_ORIENTATION:5`

A flip and/or rotation operation to be performed on the image.

The type is [D2D1_BITMAPSOURCE_ORIENTATION](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_bitmapsource_orientation).

The default value is D2D1_BITMAPSOURCE_ORIENTATION_DEFAULT.

### `D2D1_BITMAPSOURCE_PROP_FORCE_DWORD:0xffffffff`