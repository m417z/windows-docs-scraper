# ID2D1DeviceContext5::CreateColorContextFromSimpleColorProfile(const D2D1_SIMPLE_COLOR_PROFILE,ID2D1ColorContext1)

## Description

Creates a color context from a simple color profile. It is only valid to use this with the Color Management Effect in 'Best' mode.

## Parameters

### `simpleProfile` [in]

Type: **const [D2D1_SIMPLE_COLOR_PROFILE](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_simple_color_profile)***

The simple color profile to create the color context from.

### `colorContext` [out]

Type: **ID2D1ColorContext1****

The created color context.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1DeviceContext5](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext5)