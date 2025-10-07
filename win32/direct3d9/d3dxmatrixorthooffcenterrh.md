# D3DXMatrixOrthoOffCenterRH function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a customized, right-handed orthographic projection matrix.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the resulting [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrix).

*l* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Minimum x-value of view volume.

*r* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum x-value of view volume.

*b* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Minimum y-value of view volume.

*t* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum y-value of view volume.

*zn* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Minimum z-value of the view volume.

*zf* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum z-value of the view volume.

## Return value

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the resulting [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrix).

## Remarks

The [**D3DXMatrixOrthoRH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixorthorh) function is a special case of the **D3DXMatrixOrthoOffCenterRH** function. To create the same projection using **D3DXMatrixOrthoOffCenterRH**, use the following values: l = -w/2, r = w/2, b = -h/2, and t = h/2.

All the parameters of the **D3DXMatrixOrthoOffCenterRH** function are distances in camera space. The parameters describe the dimensions of the view volume.

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXMatrixOrthoOffCenterRH** function can be used as a parameter for another function.

This function uses the following formula to compute the returned matrix.

```
2/(r-l)      0            0           0
0            2/(t-b)      0           0
0            0            1/(zn-zf)   0
(l+r)/(l-r)  (t+b)/(b-t)  zn/(zn-zf)  1
```

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXMatrixOrthoRH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixorthorh)

[**D3DXMatrixOrthoLH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixortholh)

[**D3DXMatrixOrthoOffCenterLH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixorthooffcenterlh)

