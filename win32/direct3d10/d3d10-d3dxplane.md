# D3DXPLANE structure (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Describes a plane.

## Members

**a**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The a coefficient of the clipping plane in the general plane equation. See Remarks.

**b**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The b coefficient of the clipping plane in the general plane equation. See Remarks.

**c**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The c coefficient of the clipping plane in the general plane equation. See Remarks.

**d**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The d coefficient of the clipping plane in the general plane equation. See Remarks.

## Remarks

The members of the **D3DXPLANE** structure take the form of the general plane equation. They fit into the general plane equation so that ax + by + cz + dw = 0.

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-structures)

