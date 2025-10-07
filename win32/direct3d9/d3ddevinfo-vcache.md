# D3DDEVINFO\_VCACHE structure

Vertex cache optimization hints.

## Members

**Pattern**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Bit pattern. Return value must be the FOURCC ('C', 'A', 'C', 'H').

**OptMethod**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Optimizations method. Use 0 to get the longest strips. Use 1 to optimize the vertex cache usage.

**CacheSize**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Cache size used as a target for optimization. This is required only if OptMethod is 1.

**MagicNumber**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Used by internal optimization methods to determine when to restart strips. This cannot be set or modified by a user. This is required only if OptMethod is 1.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetData**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dquery9-getdata)

