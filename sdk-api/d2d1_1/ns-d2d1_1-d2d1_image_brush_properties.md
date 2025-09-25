# D2D1_IMAGE_BRUSH_PROPERTIES structure

## Description

Describes image brush features.

## Members

### `sourceRectangle`

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

The source rectangle in the image space from which the image will be tiled or interpolated.

### `extendModeX`

Type: **[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_extend_mode)**

The extend mode in the image x-axis.

### `extendModeY`

Type: **[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_extend_mode)**

The extend mode in the image y-axis.

### `interpolationMode`

Type: **[D2D1_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

The interpolation mode to use when scaling the image brush.

## See also

[ID2D1DeviceContext::CreateImageBrush](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createimagebrush(id2d1image_constd2d1_image_brush_properties__constd2d1_brush_properties__id2d1imagebrush))

[ID2D1ImageBrush](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1imagebrush)