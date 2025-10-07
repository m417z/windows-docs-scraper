# D3DXColorAdjustSaturation function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Adjusts the saturation value of a color.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure that is the result of the operation.

*pC* \[in\]

Type: **const [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a source [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure.

*s* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Saturation value. This parameter linearly interpolates between the color converted to grayscale and the original color, pC. There are no limits on the value of s. If s is 0, the returned color is the grayscale color. If s is 1, the returned color is the original color.

## Return value

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

This function returns a pointer to a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure that is the result of the saturation adjustment.

## Remarks

The input alpha channel is copied, unmodified, to the output alpha channel.

The return value for this function is the same value returned in the pOut parameter. In this way, this function can be used as a parameter for another function.

This function interpolates the red, green, and blue color components of a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure between an unsaturated color and a color, as shown in the following example.

```
    // Approximate values for each component's contribution to luminance.
    // Based upon the NTSC standard described in ITU-R Recommendation BT.709.
    FLOAT grey = pC->r * 0.2125f + pC->g * 0.7154f + pC->b * 0.0721f;

    pOut->r = grey + s * (pC->r - grey);
```

If s is greater than 0 and less than 1, the saturation is decreased. If s is greater than 1, the saturation is increased.

The grayscale color is computed as:

```
r = g = b = 0.2125*r + 0.7154*g + 0.0721*b
```

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXColorAdjustContrast**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcoloradjustcontrast)

