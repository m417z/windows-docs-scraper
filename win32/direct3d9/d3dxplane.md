# D3DXPLANE structure (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

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

The members of the **D3DXPLANE** structure take the form of the general plane equation. They fit into the general plane equation so that **a**x + **b**y + **c**z + **d**w = 0.

C++ programmers can take advantage of operator overloading and type casting with the [**D3DXPLANE Extensions**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane-extensions) which implement overloaded constructors and assignment, unary, and binary (including equality) operators.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

