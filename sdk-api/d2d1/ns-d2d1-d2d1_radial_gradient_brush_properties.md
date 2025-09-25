# D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES structure

## Description

Contains the gradient origin offset and the size and position of the gradient ellipse for an [ID2D1RadialGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1radialgradientbrush).

## Members

### `center`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

In the brush's coordinate space, the center of the gradient ellipse.

### `gradientOriginOffset`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

In the brush's coordinate space, the offset of the gradient origin relative to the gradient ellipse's center.

### `radiusX`

Type: **FLOAT**

In the brush's coordinate space, the x-radius of the gradient ellipse.

### `radiusY`

Type: **FLOAT**

In the brush's coordinate space, the y-radius of the gradient ellipse.

## Remarks

Different values for *center*, *gradientOriginOffset*, *radiusX* and/or *radiusY* produce different gradients. The following illustration shows several radial gradients that have different gradient origin offsets, creating the appearance of the light illuminating the circles from different angles.

![Illustration of four circles with radial gradients that have different origin offsets](https://learn.microsoft.com/windows/win32/api/d2d1/images/RadialGradient.png)

For convenience, Direct2D provides the [D2D1::RadialGradientBrushProperties](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-radialgradientbrushproperties) function for creating new **D2D1_RADIAL_GRADIENT_BRUSH** structures.

## Examples

The following example calls [CreateRadialGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-createradialgradientbrush(constd2d1_radial_gradient_brush_properties__constd2d1_brush_properties__id2d1gradientstopcollection_id2d1radialgradientbrush)) to create an [ID2D1RadialGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1radialgradientbrush). It uses the [D2D1::RadialGradientBrushProperties](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-radialgradientbrushproperties) helper function to create a **D2D1_RADIAL_GRADIENT_BRUSH** structure that has a *center* value of (75, 5), a *gradientOriginOffset* of (0, 0), and a *radiusX* and *radiusY* of to 75 and passes the structure to the **CreateRadialGradientBrush** method. When the gradient brush is used to fill a rectangle, it produces output as shown in the following illustration.

![Illustration of a circle with a radial gradient brush](https://learn.microsoft.com/windows/win32/api/d2d1/images/brushes_ovw_radials.png)

```cpp
// The center of the gradient is in the center of the box.
// The gradient origin offset was set to zero(0, 0) or center in this case.
if (SUCCEEDED(hr))
{
    hr = m_pRenderTarget->CreateRadialGradientBrush(
        D2D1::RadialGradientBrushProperties(
            D2D1::Point2F(75, 75),
            D2D1::Point2F(0, 0),
            75,
            75),
        pGradientStops,
        &m_pRadialGradientBrush
        );
}

```

For more information about radial gradient brushes, see the [How to Create a Radial Gradient Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-radial-gradient-brush) topic and the [Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview).

## See also

[Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview)

[D2D1::RadialGradientBrushProperties](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-radialgradientbrushproperties)

[How to Create a Radial Gradient Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-radial-gradient-brush)

[ID2D1RadialGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1radialgradientbrush)