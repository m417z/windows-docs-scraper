# D3DMATERIAL9 structure

Specifies material properties.

## Members

**Diffuse**

Type: **[**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue)**

Value specifying the diffuse color of the material. See [**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue).

**Ambient**

Type: **[**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue)**

Value specifying the ambient color of the material. See [**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue).

**Specular**

Type: **[**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue)**

Value specifying the specular color of the material. See [**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue).

**Emissive**

Type: **[**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue)**

Value specifying the emissive color of the material. See [**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue).

**Power**

Type: **float**

Floating-point value specifying the sharpness of specular highlights. The higher the value, the sharper the highlight.

## Remarks

To turn off specular highlights, set D3DRS\_SPECULARENABLE to **FALSE**, using [**D3DRENDERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3drenderstatetype). This is the fastest option because no specular highlights will be calculated.

For more information about using the lighting engine to calculate specular lighting, see [Specular Lighting (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/specular-lighting).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**IDirect3DDevice9::GetMaterial**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getmaterial)

[**IDirect3DDevice9::SetMaterial**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setmaterial)

