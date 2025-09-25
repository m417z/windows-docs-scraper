# ID2D1GradientStopCollection1::GetPreInterpolationSpace

## Description

Gets the color space of the input colors as well as the space in which gradient stops are interpolated.

## Return value

Type: **[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)**

This method returns the color space.

## Remarks

If this object was created using [ID2D1RenderTarget::CreateGradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-creategradientstopcollection(constd2d1_gradient_stop_uint32_d2d1_gamma_d2d1_extend_mode_id2d1gradientstopcollection)), this method returns the color space related to the color interpolation gamma.

## See also

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1DeviceContext::CreateGradientStopCollection](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-creategradientstopcollection)

[ID2D1GradientStopCollection1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gradientstopcollection1)

[ID2D1RenderTarget::CreateGradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-creategradientstopcollection(constd2d1_gradient_stop_uint32_d2d1_gamma_d2d1_extend_mode_id2d1gradientstopcollection))