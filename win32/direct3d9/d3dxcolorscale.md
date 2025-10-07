# D3DXColorScale function

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Scales a color value.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure that is the result of the operation.

*pC* \[in\]

Type: **const [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a source [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure.

*s* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Scale factor. It scales the color, treating it like a 4D vector. There are no limits on the value of s. If s is 1, the resulting color is the original color.

## Return value

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

This function returns a pointer to a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure that is the scaled color value.

## Remarks

The return value for this function is the same value returned in the pOut parameter. In this way, the **D3DXColorScale** function can be used as a parameter for another function.

This function computes the scaled color value by multiplying the color components of the [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure by the specified scale factor, as shown in the following example.

```
pOut->r = pC->r * s;
```

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXColorLerp**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolorlerp)

[**D3DXColorModulate**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolormodulate)

[**D3DXColorNegative**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolornegative)

