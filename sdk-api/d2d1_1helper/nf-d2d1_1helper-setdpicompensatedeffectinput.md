# SetDpiCompensatedEffectInput function

## Description

Sets a bitmap as an effect input, while inserting a DPI compensation effect
to preserve visual appearance as the device context's DPI changes.

## Parameters

### `deviceContext` [in]

Type: **[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)***

The device context that is the creator of the effect.

### `effect` [in]

Type: **[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)***

The function sets the input of this effect.

### `inputIndex`

Type: **UINT32**

The index of the input to be set.

### `inputBitmap` [in, optional]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1bitmap)***

The input bitmap.

### `interpolationMode`

Type: **[D2D1_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_interpolation_mode)**

The interpolation mode for the DPI compensation effect.

### `borderMode`

Type: **[D2D1_BORDER_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_border_mode)**

The border mode for the DPI compensation effect.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.