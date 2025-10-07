# D3DXMatrixScaling function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a matrix that scales along the x-axis, the y-axis, and the z-axis.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrix) structure that is the result of the operation.

*sx* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Scaling factor that is applied along the x-axis.

*sy* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Scaling factor that is applied along the y-axis.

*sz* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Scaling factor that is applied along the z-axis.

## Return value

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the scaling transformation D3DXMATRIX.

## Remarks

The return value for this function is the same value returned in the pOut parameter. In this way, the D3DXMatrixScaling function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

