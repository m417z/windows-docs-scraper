## Description

Creates an [ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1lineargradientbrush) that contains the specified gradient stops and has the specified transform and base opacity.

## Parameters

### `linearGradientBrushProperties`

Type: [in] **const [D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_linear_gradient_brush_properties) &**

The start and end points of the gradient.

### `brushProperties`

Type: [in] **const [D2D1_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_brush_properties) &**

The transform and base opacity of the new brush.

### `gradientStopCollection`

Type: [in] **[ID2D1GradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1gradientstopcollection)***

A collection of [D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_gradient_stop) structures that describe the colors in the brush's gradient and their locations along the gradient line.

### `linearGradientBrush`

Type: [out] **[ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1lineargradientbrush)****

When this method returns, contains the address of a pointer to the new brush. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[Brushes Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-brushes-overview)

[CreateGradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-creategradientstopcollection(constd2d1_gradient_stop_uint32_d2d1_gamma_d2d1_extend_mode_id2d1gradientstopcollection))

[How to Create a Linear Gradient Brush](https://learn.microsoft.com/windows/win32/Direct2D/how-to-create-a-linear-gradient-brush)

[ID2D1GradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1gradientstopcollection)

[ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1lineargradientbrush)

[ID2D1RadialGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1radialgradientbrush)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)