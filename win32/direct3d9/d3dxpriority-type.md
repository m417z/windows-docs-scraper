# D3DXPRIORITY\_TYPE enumeration

Defines the priority type to which an animation track is assigned.

## Constants

**D3DXPRIORITY\_LOW**

Track should be blended with all the low-priority tracks before the low-priority blend is mixed with the high-priority blend.

**D3DXPRIORITY\_HIGH**

Track should be blended with all the high-priority tracks before the high-priority blend is mixed with the low-priority blend.

**D3DXPRIORITY\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Tracks with the same priority are blended together, and the two resulting values are then blended using the priority blend factor.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

