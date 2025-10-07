# D3DLIGHTTYPE enumeration

Defines the light type.

## Constants

**D3DLIGHT\_POINT**

Light is a point source. The light has a position in space and radiates light in all directions.

**D3DLIGHT\_SPOT**

Light is a spotlight source. This light is like a point light, except that the illumination is limited to a cone. This light type has a direction and several other parameters that determine the shape of the cone it produces. For information about these parameters, see the [**D3DLIGHT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dlight9) structure.

**D3DLIGHT\_DIRECTIONAL**

Light is a directional light source. This is equivalent to using a point light source at an infinite distance.

**D3DLIGHT\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Directional lights are slightly faster than point light sources, but point lights look a little better. Spotlights offer interesting visual effects but are computationally time-consuming.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DLIGHT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dlight9)

