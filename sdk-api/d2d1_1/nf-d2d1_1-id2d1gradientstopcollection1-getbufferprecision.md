# ID2D1GradientStopCollection1::GetBufferPrecision

## Description

Gets the precision of the gradient buffer.

## Return value

Type: **[D2D1_BUFFER_PRECISION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_buffer_precision)**

The buffer precision of the gradient buffer.

## Remarks

If this object was created using [ID2D1RenderTarget::CreateGradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-creategradientstopcollection(constd2d1_gradient_stop_uint32_d2d1_gamma_d2d1_extend_mode_id2d1gradientstopcollection)), this method returns D2D1_BUFFER_PRECISION_8BPC_UNORM.

## See also

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1DeviceContext::CreateGradientStopCollection](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-creategradientstopcollection)

[ID2D1GradientStopCollection1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gradientstopcollection1)

[ID2D1RenderTarget::CreateGradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-creategradientstopcollection(constd2d1_gradient_stop_uint32_d2d1_gamma_d2d1_extend_mode_id2d1gradientstopcollection))