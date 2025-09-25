# D2D1_GRADIENT_STOP structure

## Description

Contains the position and color of a gradient stop.

## Members

### `position`

Type: **FLOAT**

A value that indicates the relative position of the gradient stop in the brush. This value must be in the [0.0f, 1.0f] range if the gradient stop is to be seen explicitly.

### `color`

Type: **[D2D1_COLOR_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-color-f)**

The color of the gradient stop.

## Remarks

Gradient stops can be specified in any order if they are at different positions. Two stops may share a position. In this case, the first stop specified is treated as the "low" stop (nearer 0.0f) and subsequent stops are treated as "higher" (nearer 1.0f). This behavior is useful if a caller wants an instant transition in the middle of a stop.

Typically, there are at least two points in a collection, although creation with only one stop is permitted. For example, one point is at position 0.0f, another point is at position 1.0f, and additional points are distributed in the [0, 1] range. Where the gradient progression is beyond the range of [0, 1], the stops are stored, but may affect the gradient.

When drawn, the [0, 1] range of positions is mapped to the brush, in a brush-dependent way. For details, see [ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1lineargradientbrush) and [ID2D1RadialGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1radialgradientbrush).

Gradient stops with a position outside the [0, 1] range cannot be seen explicitly, but they can still affect the colors produced in the [0, 1] range. For example, a two-stop gradient {{0.0f, Black}, {2.0f, White}} is indistinguishable visually from {{0.0f, Black}, {1.0f, Mid-level gray}}. Also, the colors are clamped before interpolation.

## Examples

The following example creates an array of gradient stops, then uses them to create
an [ID2D1GradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1gradientstopcollection).

```cpp
// Create an array of gradient stops to put in the gradient stop
// collection that will be used in the gradient brush.
ID2D1GradientStopCollection *pGradientStops = NULL;

D2D1_GRADIENT_STOP gradientStops[2];
gradientStops[0].color = D2D1::ColorF(D2D1::ColorF::Yellow, 1);
gradientStops[0].position = 0.0f;
gradientStops[1].color = D2D1::ColorF(D2D1::ColorF::ForestGreen, 1);
gradientStops[1].position = 1.0f;
// Create the ID2D1GradientStopCollection from a previously
// declared array of D2D1_GRADIENT_STOP structs.
hr = m_pRenderTarget->CreateGradientStopCollection(
    gradientStops,
    2,
    D2D1_GAMMA_2_2,
    D2D1_EXTEND_MODE_CLAMP,
    &pGradientStops
    );

```

The next code example uses the [ID2D1GradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1gradientstopcollection) to
create an [ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1lineargradientbrush).

```cpp
// The line that determines the direction of the gradient starts at
// the upper-left corner of the square and ends at the lower-right corner.

if (SUCCEEDED(hr))
{
    hr = m_pRenderTarget->CreateLinearGradientBrush(
        D2D1::LinearGradientBrushProperties(
            D2D1::Point2F(0, 0),
            D2D1::Point2F(150, 150)),
        pGradientStops,
        &m_pLinearGradientBrush
        );
}

```

## See also

[Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview)

[CreateGradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-creategradientstopcollection(constd2d1_gradient_stop_uint32_d2d1_gamma_d2d1_extend_mode_id2d1gradientstopcollection))

[How to Create a Linear Gradient Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-linear-gradient-brush)

[How to Create a Radial Gradient Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-radial-gradient-brush)

[ID2D1GradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1gradientstopcollection)

[ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1lineargradientbrush)

[ID2D1RadialGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1radialgradientbrush)