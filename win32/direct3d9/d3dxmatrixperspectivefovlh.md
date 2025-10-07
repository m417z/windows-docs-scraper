# D3DXMatrixPerspectiveFovLH function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a left-handed perspective projection matrix based on a field of view.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is the result of the operation.

*fovy* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Field of view in the y direction, in radians.

*Aspect* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Aspect ratio, defined as view space width divided by height.

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

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXMatrixPerspectiveFovLH** function can be used as a parameter for another function.

To change the aspect ratio axis, use the calculation formula: fovy = 2 * math.atan(math.tan(fovy * 0.5) / aspect). Alternatively, add X and Y aspect ratio variables in the structure to scale the vertical view space: fovy = 2 * math.atan(math.tan(fovy * 0.5) / aspectY), aspect = aspectX * aspect Y.

This function computes the returned matrix as shown:

```
xScale     0          0               0
0        yScale       0               0
0          0       zf/(zf-zn)         1
0          0       -zn*zf/(zf-zn)     0
where:
yScale = cot(fovY/2)

xScale = yScale / aspect ratio
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

[**D3DXMatrixPerspectiveOffCenterRH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixperspectiveoffcenterrh)

[**D3DXMatrixPerspectiveOffCenterLH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixperspectiveoffcenterlh)

