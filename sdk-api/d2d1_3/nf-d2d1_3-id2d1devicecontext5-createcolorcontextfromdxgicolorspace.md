# ID2D1DeviceContext5::CreateColorContextFromDxgiColorSpace

## Description

Creates a color context from a DXGI color space type. It is only valid to use this with the Color Management Effect in 'Best' mode.

## Parameters

### `colorSpace`

Type: **DXGI_COLOR_SPACE_TYPE**

The color space to create the color context from.

### `colorContext` [out]

Type: **ID2D1ColorContext1****

The created color context.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1DeviceContext5](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext5)