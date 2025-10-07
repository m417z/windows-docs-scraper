# D3DXPATCHMESHTYPE enumeration

Mesh patch types.

## Constants

**D3DXPATCHMESH\_RECT**

Rectangle patch mesh type.

**D3DXPATCHMESH\_TRI**

Triangle patch mesh type.

**D3DXPATCHMESH\_NPATCH**

N-patch mesh type.

**D3DXPATCHMESH\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Triangle patches have three sides and are described in [**D3DTRIPATCH\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtripatch-info). Rectangle patches are four-sided and are described in [**D3DRECTPATCH\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3drectpatch-info).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

[Using Higher-Order Primitives (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/using-higher-order-primitives)

