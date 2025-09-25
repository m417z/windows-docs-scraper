# LinearGradientBrushProperties function

## Description

Creates a [D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_linear_gradient_brush_properties) structure.

## Parameters

### `startPoint` [in, ref]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The start point, in the brush's coordinate space, of the gradient axis.

### `endPoint` [in, ref]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The end point, in the brush's coordinate space, of the gradient axis.

## Return value

Type: **[D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_linear_gradient_brush_properties)**

A structure that contains the start and end point of the gradient axis for an [ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1lineargradientbrush).