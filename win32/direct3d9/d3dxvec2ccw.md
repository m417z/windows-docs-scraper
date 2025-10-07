# D3DXVec2CCW function

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Returns the z-component by taking the cross product of two 2D vectors.

## Parameters

*pV1* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure.

*pV2* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure.

## Return value

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The z-component.

## Remarks

This function determines the z-component by determining the cross-product based on the following formula: ((x1,y1,0) cross (x2,y2,0)). Or as shown in the following example.

```
pV1->x * pV2->y - pV1->y * pV2->x
```

If the value of the z-component is positive, the vector V2 is counterclockwise from the vector V1. This information is useful for back-face culling.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXVec2Dot**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvec2dot)

