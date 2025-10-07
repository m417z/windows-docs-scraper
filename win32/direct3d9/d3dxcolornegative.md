# D3DXColorNegative function

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Creates the negative color value of a color value.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure that is the result of the operation.

*pC* \[in\]

Type: **const [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a source [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure.

## Return value

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

This function returns a pointer to a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure that is the negative color value of the color value.

## Remarks

The input alpha channel is copied, unmodified, to the output alpha channel.

The return value for this function is the same value returned in the pOut parameter. In this way, the **D3DXColorNegative** function can be used as a parameter for another function.

This function returns the negative color value by subtracting 1.0 from the color components of the [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure, as shown in the following example.

```
pOut->r = 1.0f - pC->r;
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

[**D3DXColorScale**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolorscale)

