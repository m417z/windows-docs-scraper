# ID2D1CommandSink::DrawBitmap

## Description

Draws a bitmap to the render target.

## Parameters

### `bitmap` [in]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1bitmap)***

The bitmap to draw.

### `destinationRectangle` [in, optional]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

The destination rectangle. The default is the size of the bitmap and the location is the upper left corner of the render target.

### `opacity`

Type: **FLOAT**

The opacity of the bitmap.

### `interpolationMode`

Type: **[D2D1_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_interpolation_mode)**

The interpolation mode to use.

### `sourceRectangle` [in, optional]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

An optional source rectangle.

### `perspectiveTransform` [in, optional]

Type: **const [D2D1_MATRIX_4X4_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-4x4-f)**

An optional perspective transform.

## Return value

This method does not return a value.

## Remarks

The *destinationRectangle* parameter defines the rectangle in the target where the bitmap will appear (in device-independent pixels (DIPs)). This is affected by the currently set transform and the perspective transform, if set. If you specify NULL, then the destination rectangle is (left=0, top=0, right = width(*sourceRectangle*), bottom = height(*sourceRectangle*).

The *sourceRectangle* defines the sub-rectangle of the source bitmap (in DIPs). **DrawBitmap** clips this rectangle to the size of the source bitmap, so it's impossible to sample outside of the bitmap. If you specify NULL, then the source rectangle is taken to be the size of the source bitmap.

The *perspectiveTransform* is specified in addition to the transform on device context.

## See also

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)