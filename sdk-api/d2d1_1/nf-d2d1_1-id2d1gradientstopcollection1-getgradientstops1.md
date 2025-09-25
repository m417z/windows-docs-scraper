# ID2D1GradientStopCollection1::GetGradientStops1

## Description

Copies the gradient stops from the collection into memory.

## Parameters

### `gradientStops` [out]

Type: **[D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_gradient_stop)***

When this method returns, contains a pointer to a one-dimensional array of [D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_gradient_stop) structures.

### `gradientStopsCount`

Type: **UINT**

The number of gradient stops to copy.

## Remarks

If the [ID2D1DeviceContext::CreateGradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-creategradientstopcollection), this method returns the same values specified in the creation method. If the **ID2D1GradientStopCollection1** object was created using **ID2D1RenderTarget::CreateGradientStopCollection**, the stops returned here will first be transformed into the gamma space specified by the *colorInterpolationGamma* parameter. See the [ID2D1DeviceContext::CreateGradientStopCollection](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-creategradientstopcollection) method for more info about color space and gamma space.

If *gradientStopsCount* is less than the number of gradient stops in the collection, the remaining gradient stops are omitted. If *gradientStopsCount* is larger than the number of gradient stops in the collection, the extra gradient stops are set to **NULL**. To obtain the number of gradient stops in the collection, use the [GetGradientStopCount](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1gradientstopcollection-getgradientstopcount) method.

## See also

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1DeviceContext::CreateGradientStopCollection](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-creategradientstopcollection)

[ID2D1GradientStopCollection1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gradientstopcollection1)

[ID2D1RenderTarget::CreateGradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-creategradientstopcollection(constd2d1_gradient_stop_uint32_d2d1_gamma_d2d1_extend_mode_id2d1gradientstopcollection))