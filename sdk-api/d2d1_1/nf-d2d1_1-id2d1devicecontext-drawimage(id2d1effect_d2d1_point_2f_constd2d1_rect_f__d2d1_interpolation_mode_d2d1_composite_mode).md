# ID2D1DeviceContext::DrawImage(ID2D1Effect,D2D1_POINT_2F,const D2D1_RECT_F &,D2D1_INTERPOLATION_MODE,D2D1_COMPOSITE_MODE)

## Description

Draws an image to the device context.

## Parameters

### `effect` [in]

Type: **[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)***

The image to be drawn to the device context.

### `targetOffset` [in, optional]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The offset in the destination space that the image will be rendered to. The entire logical extent of the image will be rendered to the corresponding destination. If not specified, the destination origin will be (0, 0). The top-left corner of the image will be mapped to the target offset. This will not necessarily be the origin. This default value is *NULL*.

### `imageRectangle` [in, ref, optional]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

The corresponding rectangle in the image space will be mapped to the given origins when processing the image. This default value is *NULL*.

### `interpolationMode`

Type: **[D2D1_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_interpolation_mode)**

The interpolation mode that will be used to scale the image if necessary.

### `compositeMode`

Type: **[D2D1_COMPOSITE_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_composite_mode)**

The composite mode that will be applied to the limits of the currently selected clip. The default value is **D2D1_COMPOSITE_MODE_SOURCE_OVER**

## Remarks

If *interpolationMode* is **D2D1_INTERPOLATION_MODE_HIGH_QUALITY**, different scalers will be used depending on the scale factor implied by the world transform.

Any invalid rectangles accumulated on any effect that is drawn by this call will be discarded regardless of which portion of the image rectangle is drawn.

If *compositeMode* is **D2D1_COMPOSITE_MODE_SOURCE_OVER**, [DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawimage(id2d1effect_constd2d1_point_2f_constd2d1_rect_f_d2d1_interpolation_mode_d2d1_composite_mode)) will use the currently selected primitive blend specified by [ID2D1DeviceContext::SetPrimitiveBlend](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-setprimitiveblend). If *compositeMode* is not **D2D1_COMPOSITE_MODE_SOURCE_OVER**, the image will be extended to transparent up to the current axis-aligned clip.

If there is an image rectangle and a world transform, this is equivalent to inserting a clip effect to represent the image rectangle and a 2D affine transform to take into account the world transform.

## See also

[ID2D1Bitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1bitmap)

[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)

[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)