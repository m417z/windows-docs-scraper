# D3DMATERIALCOLORSOURCE enumeration

Defines the location at which a color or color component must be accessed for lighting calculations.

## Constants

**D3DMCS\_MATERIAL**

Use the color from the current material.

**D3DMCS\_COLOR1**

Use the diffuse vertex color.

**D3DMCS\_COLOR2**

Use the specular vertex color.

**D3DMCS\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

These flags are used to set the value of the following render states in the [**D3DRENDERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3drenderstatetype) enumerated type.

- D3DRS\_AMBIENTMATERIALSOURCE
- D3DRS\_DIFFUSEMATERIALSOURCE
- D3DRS\_EMISSIVEMATERIALSOURCE
- D3DRS\_SPECULARMATERIALSOURCE

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DRENDERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3drenderstatetype)

