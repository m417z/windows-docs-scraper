# ID2D1CommandSink::DrawImage

## Description

Draws the provided image to the command sink.

## Parameters

### `image` [in]

Type: **[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)***

The image to be drawn to the command sink.

### `targetOffset` [in, optional]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

This defines the offset in the destination space that the image will be rendered to. The entire logical extent of the image will be rendered to the corresponding destination. If not specified, the destination origin will be (0, 0). The top-left corner of the image will be mapped to the target offset. This will not necessarily be the origin.

### `imageRectangle` [in, optional]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The corresponding rectangle in the image space will be mapped to the provided origins when processing the image.

### `interpolationMode`

Type: **[D2D1_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_interpolation_mode)**

The interpolation mode to use to scale the image if necessary.

### `compositeMode`

Type: **[D2D1_COMPOSITE_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_composite_mode)**

If specified, the composite mode that will be applied to the limits of the currently selected clip.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

Because the image can itself be a command list or contain an effect graph that in turn contains a command list, this method can result in recursive processing.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1DeviceContext::DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawimage(id2d1effect_constd2d1_point_2f_constd2d1_rect_f_d2d1_interpolation_mode_d2d1_composite_mode))