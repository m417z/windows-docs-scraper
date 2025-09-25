# D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES structure

## Description

Contains the starting point and endpoint of the gradient axis for an [ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1lineargradientbrush).

## Members

### `startPoint`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

In the brush's coordinate space, the starting point of the gradient axis.

### `endPoint`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

In the brush's coordinate space, the endpoint of the gradient axis.

## Remarks

Use this method when creating new [ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1lineargradientbrush) objects with the [CreateLinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-createlineargradientbrush(constd2d1_linear_gradient_brush_properties__constd2d1_brush_properties__id2d1gradientstopcollection_id2d1lineargradientbrush)) method. For convenience, Direct2D provides the [D2D1::LinearGradientBrushProperties](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-lineargradientbrushproperties) helper function for creating new **D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES** structures.

The following illustration shows how a linear gradient changes as you change its start and end points. For the first gradient, the start point is set to (0,0) and the end point to (150, 50); this creates a diagonal gradient that starts at the upper-left corner and extends to the lower-right corner of the area being painted. When you set the start point to (0, 25) and the end point to (150, 25), a horizontal gradient is created. Similarly, setting the start point to (75, 0) and the end point to (75, 50) creates a vertical gradient. Setting the start point to (0, 50) and the end point to (150, 0) creates a diagonal gradient that starts at the lower-left corner and extends to the upper-right corner of the area being painted.

![Illustration of four gradients with different axes](https://learn.microsoft.com/windows/win32/api/d2d1/images/Linear_Gradients.png)

## Examples

The following example uses the [CreateLinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-createlineargradientbrush(constd2d1_linear_gradient_brush_properties__constd2d1_brush_properties__id2d1gradientstopcollection_id2d1lineargradientbrush)) method to create an [ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1lineargradientbrush) (*m_pLinearGradientBrush*). It uses the [D2D1::LinearGradientBrushProperties](https://learn.microsoft.com/windows/win32/api/d2d1helper/nf-d2d1helper-lineargradientbrushproperties) helper method to create a **D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES** structure that contains a start point of (0, 0) and end point of (150, 150) and passes it to the **CreateLinearGradientBrush** method.

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

For more information about creating and using linear gradient brushes, see
the [How to Create a Linear Gradient Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-linear-gradient-brush) topic and
the [Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview).

## See also

[Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview)

[How to Create a Linear Gradient Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-linear-gradient-brush)