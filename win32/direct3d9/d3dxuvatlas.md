# D3DXUVATLAS enumeration

Defines options for performing geodesic distance calculations, when fitting a texture to a curved surface. Use this flag to choose between high quality versus fast calculations when computing a texture atlas.

## Constants

**D3DXUVATLAS\_DEFAULT**

Meshes with more than 25k faces will have the fast geodasic distance method applied to them while meshes with fewer than 25k faces will have the higher quality geodesic distance method applied to them instead.

**D3DXUVATLAS\_GEODESIC\_FAST**

Uses approximations to improve charting speed at the cost of added stretch or more charts being output for the mesh.

**D3DXUVATLAS\_GEODESIC\_QUALITY**

Provides better quality charts, but requires more time and memory than fast.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

