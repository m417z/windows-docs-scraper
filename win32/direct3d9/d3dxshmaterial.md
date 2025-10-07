# D3DXSHMATERIAL structure

Spherical harmonic (SH) precomputed radiance transfer (PRT) material characteristics.

## Members

**Diffuse**

Type: **[**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue)**

Diffuse albedo of the surface. This value is ignored if the object is a mirror.

**bMirror**

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Must be set to **FALSE**.

**bSubSurf**

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Set to **TRUE** to enable subsurface scattering; any object that does subsurface scattering cannot be a mirror.

**RelativeIndexOfRefraction**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Relative index of refraction is the ratio between two absolute indexes of refraction. An index of refraction is the ratio of the sine of the angle of incidence to the sine of the angle of refraction.

**Absorption**

Type: **[**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue)**

The absorption coefficient is a parameter to the volume rendering equation used to model light propagation in a participating medium.

**ReducedScattering**

Type: **[**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue)**

The reduced scattering coefficient is a parameter to the volume rendering equation used to model light propagation in a participating medium.

## Remarks

Non-spectral scenes use the red channel from the materials instead of the luminance value.

For more information about PRT see:

- Jensen, Henrik Wann, et al. Siggraph Proceedings: A Practical Model for Subsurface Light Transport, 2001.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

