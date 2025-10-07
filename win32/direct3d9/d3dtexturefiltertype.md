# D3DTEXTUREFILTERTYPE enumeration

Defines texture filtering modes for a texture stage.

## Constants

**D3DTEXF\_NONE**

When used with [**D3DSAMP\_MIPFILTER**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype), disables mipmapping.

**D3DTEXF\_POINT**

When used with [**D3DSAMP\_ MAGFILTER**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype) or [**D3DSAMP\_MINFILTER**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype), specifies that point filtering is to be used as the texture magnification or minification filter respectively. When used with **D3DSAMP\_MIPFILTER**, enables mipmapping and specifies that the rasterizer chooses the color from the texel of the nearest mip level.

**D3DTEXF\_LINEAR**

When used with [**D3DSAMP\_ MAGFILTER**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype) or [**D3DSAMP\_MINFILTER**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype), specifies that linear filtering is to be used as the texture magnification or minification filter respectively. When used with **D3DSAMP\_MIPFILTER**, enables mipmapping and trilinear filtering; it specifies that the rasterizer interpolates between the two nearest mip levels.

**D3DTEXF\_ANISOTROPIC**

When used with [**D3DSAMP\_ MAGFILTER**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype) or [**D3DSAMP\_MINFILTER**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype), specifies that anisotropic texture filtering used as a texture magnification or minification filter respectively. Compensates for distortion caused by the difference in angle between the texture polygon and the plane of the screen. Use with **D3DSAMP\_MIPFILTER** is undefined.

**D3DTEXF\_PYRAMIDALQUAD**

A 4-sample tent filter used as a texture magnification or minification filter. Use with [**D3DSAMP\_MIPFILTER**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype) is undefined.

**D3DTEXF\_GAUSSIANQUAD**

A 4-sample Gaussian filter used as a texture magnification or minification filter. Use with [**D3DSAMP\_MIPFILTER**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype) is undefined.

**D3DTEXF\_CONVOLUTIONMONO**

Convolution filter for monochrome textures. See [D3DFMT\_A1](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat).

Differences between Direct3D 9 and Direct3D 9Ex:

- This flag is available in Direct3D 9Ex only.

Use with [**D3DSAMP\_MIPFILTER**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype) is undefined.

**D3DTEXF\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

D3DTEXTUREFILTERTYPE is used by [**IDirect3DDevice9::SetSamplerState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setsamplerstate) along with [**D3DSAMPLERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype) to define texture filtering modes for a texture stage.

To check if a format supports texture filter types other than D3DTEXF\_POINT (which is always supported), call [**IDirect3D9::CheckDeviceFormat**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-checkdeviceformat) with D3DUSAGE\_QUERY\_FILTER.

Set a texture stage's magnification filter by calling [**IDirect3DDevice9::SetSamplerState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setsamplerstate) with the D3DSAMP\_MAGFILTER value as the second parameter and one member of this enumeration as the third parameter.

Set a texture stage's minification filter by calling [**IDirect3DDevice9::SetSamplerState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setsamplerstate) with the D3DSAMP\_MINFILTER value as the second parameter and one member of this enumeration as the third parameter.

Set the texture filter to use between-mipmap levels by calling [**IDirect3DDevice9::SetSamplerState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setsamplerstate) with the D3DSAMP\_MIPFILTER value as the second parameter and one member of this enumeration as the third parameter.

Not all valid filtering modes for a device will apply to volume maps. In general, D3DTEXF\_POINT and D3DTEXF\_LINEAR magnification filters will be supported for volume maps. If D3DPTEXTURECAPS\_MIPVOLUMEMAP is set, then the D3DTEXF\_POINT mipmap filter and D3DTEXF\_POINT and D3DTEXF\_LINEAR minification filters will be supported for volume maps. The device may or may not support the D3DTEXF\_LINEAR mipmap filter for volume maps. Devices that support anisotropic filtering for 2D maps do not necessarily support anisotropic filtering for volume maps. However, applications that enable anisotropic filtering will receive the best available filtering (probably linear) if anisotropic filtering is not supported.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**ID3DXPatchMesh::GetDisplaceParam**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxpatchmesh--getdisplaceparam)

[**ID3DXPatchMesh::SetDisplaceParam**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxpatchmesh--setdisplaceparam)

[**D3DSAMPLERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype)

[**IDirect3DDevice9::SetSamplerState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setsamplerstate)

