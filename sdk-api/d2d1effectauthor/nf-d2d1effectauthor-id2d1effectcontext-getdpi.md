# ID2D1EffectContext::GetDpi

## Description

Gets the unit mapping that an effect will use for properties that could be in either dots per inch (dpi) or pixels.

## Parameters

### `dpiX` [out]

Type: **FLOAT***

The dpi on the x-axis.

### `dpiY` [out]

Type: **FLOAT***

The dpi on the y-axis.

## Remarks

 If the [D2D1_UNIT_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_unit_mode) is **D2D1_UNIT_MODE_PIXELS**, both *dpiX* and *dpiY* will be set to 96.

## See also

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)

[ID2D1EffectImpl::PrepareForRender](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectimpl-prepareforrender)