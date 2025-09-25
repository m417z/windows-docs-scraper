# GradientStop function

## Description

Creates a [D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_gradient_stop) structure.

## Parameters

### `position`

Type: **FLOAT**

A value that indicates the relative position of the gradient stop in the brush. A value of 0.0 specifies that the stop is positioned at the beginning of the gradient vector, while a value of 1.0 specifies that the stop is positioned at the end of the gradient vector. Stops outside the 0.0-1.0 range might not be directly visible but still influence the gradient pattern.

### `color` [in, ref]

Type: **const [D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)**

The color of the gradient stop.

## Return value

Type: **[D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_gradient_stop)**

The new gradient stop.

## See also

[D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_gradient_stop)

[ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1lineargradientbrush)

[ID2D1RadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1radialgradientbrush)