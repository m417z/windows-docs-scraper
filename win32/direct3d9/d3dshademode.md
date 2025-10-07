# D3DSHADEMODE enumeration

Defines constants that describe the supported shading modes.

## Constants

**D3DSHADE\_FLAT**

Flat shading mode. The color and specular component of the first vertex in the triangle are used to determine the color and specular component of the face. These colors remain constant across the triangle; that is, they are not interpolated. The specular alpha is interpolated. See Remarks.

**D3DSHADE\_GOURAUD**

Gouraud shading mode. The color and specular components of the face are determined by a linear interpolation between all three of the triangle's vertices.

**D3DSHADE\_PHONG**

Not supported.

**D3DSHADE\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

The first vertex of a triangle for flat shading mode is defined in the following manner.

- For a triangle list, the first vertex of the triangle i is i \* 3.
- For a triangle strip, the first vertex of the triangle i is vertex i.
- For a triangle fan, the first vertex of the triangle i is vertex i + 1.

The members of this enumerated type define the vales for the D3DRS\_SHADEMODE render state.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3d9types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DRENDERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3drenderstatetype)

