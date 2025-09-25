# ID2D1DeviceContext::CreateGradientStopCollection

## Description

Creates a gradient stop collection, enabling the gradient to contain color channels with values outside of [0,1] and also enabling rendering to a high-color render target with interpolation in sRGB space.

## Parameters

### `straightAlphaGradientStops`

Type: **const [D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_gradient_stop)***

An array of color values and offsets.

### `straightAlphaGradientStopsCount`

Type: **UINT**

The number of elements in the *gradientStops* array.

### `preInterpolationSpace`

Type: **[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)**

Specifies both the input color space and the space in which the color interpolation occurs.

### `postInterpolationSpace`

Type: **[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)**

The color space that colors will be converted to after interpolation occurs.

### `bufferPrecision`

Type: **[D2D1_BUFFER_PRECISION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_buffer_precision)**

The precision of the texture used to hold interpolated values.

**Note** This method will fail if the underlying Direct3D device does not support the requested buffer precision. Use [ID2D1DeviceContext::IsBufferPrecisionSupported](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-isbufferprecisionsupported) to determine what is supported.

### `extendMode`

Type: **[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_extend_mode)**

Defines how colors outside of the range defined by the stop collection are determined.

### `colorInterpolationMode`

Type: **[D2D1_COLOR_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_interpolation_mode)**

Defines how colors are interpolated. D2D1_COLOR_INTERPOLATION_MODE_PREMULTIPLIED is the default, see Remarks for more info.

### `gradientStopCollection1` [out]

Type: **[ID2D1GradientStopCollection1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gradientstopcollection1)****

The new gradient stop collection.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |

## Remarks

This method linearly interpolates between the color stops. An optional color space conversion is applied post-interpolation. Whether and how this gamma conversion is applied is determined by the pre- and post-interpolation. This method will fail if the device context does not support the requested buffer precision.

In order to get the desired result, you need to ensure that the inputs are specified in the correct color space.

You must always specify colors in straight alpha, regardless of interpolation mode being premultiplied or straight. The interpolation mode only affects the interpolated values. Likewise, the stops returned by [ID2D1GradientStopCollection::GetGradientStops](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1gradientstopcollection-getgradientstops) will always have straight alpha.

If you specify [D2D1_COLOR_INTERPOLATION_MODE_PREMULTIPLIED](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_interpolation_mode), then all stops are premultiplied before interpolation, and then un-premultiplied before color conversion.

Starting with Windows 8, the interpolation behavior of this method has changed.

The table here shows the behavior in Windows 7 and earlier.

| Gamma | Before Interpolation Behavior | After Interpolation Behavior | GetColorInteroplationGamma (output color space) |
| --- | --- | --- | --- |
| 1.0 | Clamps the inputs and then converts from sRGB to scRGB. | Converts from scRGB to sRGB post-interpolation. | 1.0 |
| 2.2 | Clamps the inputs. | No Operation | 2.2 |

The table here shows the behavior in Windows 8 and later.

| Gamma | Before Interpolation Behavior | After Interpolation Behavior | GetColorInteroplationGamma (output color space) |
| --- | --- | --- | --- |
| sRGB to scRGB | No Operation | Clamps the outputs and then converts from sRGB to scRGB. | 1.0 |
| scRGB to sRGB | No Operation | Clamps the outputs and then converts from sRGB to scRGB. | 2.2 |
| sRGB to sRGB | No Operation | No Operation | 2.2 |
| scRGB to scRGB | No Operation | No Operation | 1.0 |

## See also

[D2D1_BUFFER_PRECISION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_buffer_precision)

[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_extend_mode)

[D2D1_GAMMA_CONVERSION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh447002(v=vs.85))

[D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_gradient_stop)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1GradientStopCollection1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gradientstopcollection1)

[ID2D1RenderTarget::CreateGradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-creategradientstopcollection(constd2d1_gradient_stop_uint32_d2d1_gamma_d2d1_extend_mode_id2d1gradientstopcollection))