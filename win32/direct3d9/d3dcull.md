# D3DCULL enumeration

Defines the supported culling modes.

## Constants

**D3DCULL\_NONE**

Do not cull back faces.

**D3DCULL\_CW**

Cull back faces with clockwise vertices.

**D3DCULL\_CCW**

Cull back faces with counterclockwise vertices.

**D3DCULL\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

The values in this enumerated type are used by the D3DRS\_CULLMODE render state. The culling modes define how back faces are culled when rendering a geometry.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9)

[**D3DRENDERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3drenderstatetype)

