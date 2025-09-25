# ID2D1BitmapBrush::SetBitmap

## Description

Specifies the bitmap source that this brush uses to paint.

## Parameters

### `bitmap` [in]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmap)***

The bitmap source used by the brush.

## Remarks

This method specifies the bitmap source that this brush uses to paint. The bitmap is not resized or rescaled automatically to fit the geometry that it fills. The bitmap stays at its native size. To resize or translate the bitmap, use the [SetTransform](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1brush-settransform(constd2d1_matrix_3x2_f)) method to apply a transform to the brush.

The native size of a bitmap is the width and height in bitmap pixels, divided by the bitmap DPI. This native size forms the base tile of the brush. To tile a subregion of the bitmap, you must generate a new bitmap containing this subregion and use **SetBitmap** to apply it to the brush.

## See also

[ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush)