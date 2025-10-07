# D3DXColorAdjustContrast function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Adjusts the contrast value of a color.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure that is the result of the operation.

*pC* \[in\]

Type: **const [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a source [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure.

*c* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Contrast value. This parameter linearly interpolates between fifty percent gray and the color, pC. There are not limits on the value of c. If this parameter is zero, then the returned color is fifty percent gray. If this parameter is 1, then the returned color is the original color.

## Return value

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

This function returns a pointer to a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure that is the result of the contrast adjustment.

## Remarks

The input alpha channel is copied, unmodified, to the output alpha channel.

The return value for this function is the same value returned in the pOut parameter. In this way, this function can be used as a parameter for another function.

This function interpolates the red, green, and blue color components of a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure between fifty percent gray and a specified contrast value, as shown in the following example.

```
pOut->r = 0.5f + c * (pC->r - 0.5f);
```

If c is greater than 0 and less than 1, the contrast is decreased. If c is greater than 1, the contrast is increased.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXColorAdjustSaturation**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcoloradjustsaturation)

