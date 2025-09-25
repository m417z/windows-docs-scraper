# ID2D1CommandSink5::BlendImage

## Description

Draws an image to the device context using the specified blend mode.
Results are equivalent to using Direct2D's built-in [Blend effect](https://learn.microsoft.com/windows/desktop/Direct2D/blend).

## Parameters

### `image` [in]

Type: **ID2D1Image***

The image to be drawn to the device context.

### `blendMode`

Type: **D2D1_BLEND_MODE**

The blend mode to be used. See [Blend modes](https://learn.microsoft.com/windows/desktop/Direct2D/blend) for more info.

### `targetOffset` [in, optional]

Type: **const D2D1_POINT_2F***

The offset in the destination space that the image will be rendered to.
The entire logical extent of the image will be rendered to the corresponding destination.
If not specified, the destination origin will be (0, 0). The top-left corner of the image will be mapped to the target offset.
This will not necessarily be the origin. The default value is NULL.

### `imageRectangle` [in, optional]

Type: **const D2D1_RECT_F***

The corresponding rectangle in the image space will be mapped to the given origins when processing the image. The default value is NULL.

### `interpolationMode`

Type: **D2D1_INTERPOLATION_MODE**

The interpolation mode that will be used to scale the image if necessary. The default value is D2D1_INTERPOLATION_MODE_LINEAR.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1CommandSink5](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1commandsink5)