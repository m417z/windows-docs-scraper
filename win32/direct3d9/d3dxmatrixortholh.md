# D3DXMatrixOrthoLH function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a left-handed orthographic projection matrix.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the resulting [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrix).

*w* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of the view volume.

*h* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height of the view volume.

*zn* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Minimum z-value of the view volume which is referred to as z-near.

*zf* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum z-value of the view volume which is referred to as z-far.

## Return value

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the resulting [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrix).

## Remarks

All the parameters of the **D3DXMatrixOrthoLH** function are distances in camera space. The parameters describe the dimensions of the view volume.

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXMatrixOrthoLH** function can be used as a parameter for another function.

This function uses the following formula to compute the returned matrix.

```
2/w  0    0           0
0    2/h  0           0
0    0    1/(zf-zn)   0
0    0   -zn/(zf-zn)  1
```

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXMatrixOrthoRH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixorthorh)

[**D3DXMatrixOrthoOffCenterRH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixorthooffcenterrh)

[**D3DXMatrixOrthoOffCenterLH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixorthooffcenterlh)

