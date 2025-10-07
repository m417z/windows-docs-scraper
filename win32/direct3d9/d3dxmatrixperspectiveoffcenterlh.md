# D3DXMatrixPerspectiveOffCenterLH function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a customized, left-handed perspective projection matrix.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is the result of the operation.

*l* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Minimum x-value of the view volume.

*r* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum x-value of the view volume.

*b* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Minimum y-value of the view volume.

*t* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum y-value of the view volume.

*zn* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Minimum z-value of the view volume.

*zf* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum z-value of the view volume.

## Return value

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to a [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is a customized, left-handed perspective projection matrix.

## Remarks

All the parameters of the **D3DXMatrixPerspectiveOffCenterLH** function are distances in camera space. The parameters describe the dimensions of the view volume.

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXMatrixPerspectiveOffCenterLH** function can be used as a parameter for another function.

This function uses the following formula to compute the returned matrix.

```
2*zn/(r-l)   0            0              0
0            2*zn/(t-b)   0              0
(l+r)/(l-r)  (t+b)/(b-t)  zf/(zf-zn)     1
0            0            zn*zf/(zn-zf)  0
```

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXMatrixPerspectiveRH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixperspectiverh)

[**D3DXMatrixPerspectiveLH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixperspectivelh)

[**D3DXMatrixPerspectiveFovRH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixperspectivefovrh)

[**D3DXMatrixPerspectiveFovLH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixperspectivefovlh)

[**D3DXMatrixPerspectiveOffCenterRH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixperspectiveoffcenterrh)

