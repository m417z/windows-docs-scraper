# D3DBASISTYPE enumeration

Defines the basis type of a high-order patch surface.

## Constants

**D3DBASIS\_BEZIER**

Input vertices are treated as a series of Bézier patches. The number of vertices specified must be divisible by 4. Portions of the mesh beyond this criterion will not be rendered. Full continuity is assumed between sub-patches in the interior of the surface rendered by each call. Only the vertices at the corners of each sub-patch are guaranteed to lie on the resulting surface.

**D3DBASIS\_BSPLINE**

Input vertices are treated as control points of a B-spline surface. The number of apertures rendered is two fewer than the number of apertures in that direction. In general, the generated surface does not contain the control vertices specified.

**D3DBASIS\_CATMULL\_ROM**

An interpolating basis defines the surface so that the surface goes through all the input vertices specified. In DirectX 8, this was D3DBASIS\_INTERPOLATE.

**D3DBASIS\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

The members of **D3DBASISTYPE** specify the formulation to be used in evaluating the high-order patch surface primitive during tessellation.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DRECTPATCH\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3drectpatch-info)

[**D3DTRIPATCH\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtripatch-info)

