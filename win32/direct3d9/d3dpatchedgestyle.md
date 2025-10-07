# D3DPATCHEDGESTYLE enumeration

Defines whether the current tessellation mode is discrete or continuous.

## Constants

**D3DPATCHEDGE\_DISCRETE**

Discrete edge style. In discrete mode, you can specify float tessellation but it will be truncated to integers.

**D3DPATCHEDGE\_CONTINUOUS**

Continuous edge style. In continuous mode, tessellation is specified as float values that can be smoothly varied to reduce "popping" artifacts.

**D3DPATCHEDGE\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Note that continuous tessellation produces a completely different tessellation pattern from the discrete one for the same tessellation values (this is more apparent in wireframe mode). Thus, 4.0 continuous is not the same as 4 discrete.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

