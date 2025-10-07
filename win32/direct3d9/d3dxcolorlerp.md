# D3DXColorLerp function

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Uses linear interpolation to create a color value.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure that is the result of the operation.

*pC1* \[in\]

Type: **const [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a source [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure.

*pC2* \[in\]

Type: **const [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a source [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure.

*s* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Parameter that linearly interpolates between the colors, pC1 and pC2, treating them both as 4D vectors. There are no limits on the value of s.

## Return value

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

This function returns a pointer to a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure that is the result of the linear interpolation.

## Remarks

The return value for this function is the same value returned in the pOut parameter. In this way, the **D3DXColorLerp** function can be used as a parameter for another function.

This function interpolates the red, green, blue, and alpha components of a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure between two colors, as shown in the following example.

```

pOut->r = pC1->r + s * (pC2->r - pC1->r);
```

If you are linearly interpolating between the colors A and B, and s is 0, the resulting color is A. If s is 1, the resulting color is color B.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXColorModulate**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolormodulate)

[**D3DXColorNegative**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolornegative)

[**D3DXColorScale**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolorscale)

