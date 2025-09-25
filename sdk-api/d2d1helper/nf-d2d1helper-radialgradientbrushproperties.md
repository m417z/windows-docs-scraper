# RadialGradientBrushProperties function

## Description

Creates a [D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_radial_gradient_brush_properties) structure.

## Parameters

### `center` [in, ref]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

In the brush's coordinate space, the center of the gradient ellipse.

### `gradientOriginOffset` [in, ref]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

In the brush's coordinate space, the offset of the gradient origin relative to the gradient ellipse's center.

### `radiusX` [in]

Type: **const FLOAT**

In the brush's coordinate space, the x-radius of the gradient ellipse.

### `radiusY` [in]

Type: **const FLOAT**

In the brush's coordinate space, the y-radius of the gradient ellipse.

## Return value

Type: **[D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_radial_gradient_brush_properties)**

A structure that contains the gradient origin offset and the size and position of the gradient ellipse for an [ID2D1RadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1radialgradientbrush).