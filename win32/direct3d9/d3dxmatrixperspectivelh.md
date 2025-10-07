# D3DXMatrixPerspectiveLH function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a left-handed perspective projection matrix

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is the result of the operation.

*w* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of the view volume at the near view-plane.

*h* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height of the view volume at the near view-plane.

*zn* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Z-value of the near view-plane.

*zf* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Z-value of the far view-plane.

## Return value

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to a [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is a left-handed perspective projection matrix.

## Remarks

All the parameters of the **D3DXMatrixPerspectiveLH** function are distances in camera space. The parameters describe the dimensions of the view volume.

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXMatrixPerspectiveLH** function can be used as a parameter for another function.

This function uses the following formula to compute the returned matrix.

```
2*zn/w  0       0              0
0       2*zn/h  0              0
0       0       zf/(zf-zn)     1
0       0       zn*zf/(zn-zf)  0
```

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXMatrixPerspectiveRH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixperspectiverh)

[**D3DXMatrixPerspectiveFovRH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixperspectivefovrh)

[**D3DXMatrixPerspectiveFovLH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixperspectivefovlh)

[**D3DXMatrixPerspectiveOffCenterRH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixperspectiveoffcenterrh)

[**D3DXMatrixPerspectiveOffCenterLH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixperspectiveoffcenterlh)

