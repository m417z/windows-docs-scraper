# D3DXFilterTexture function

Filters mipmap levels of a texture.

## Parameters

*pBaseTexture* \[in\]

Type: **[**LPDIRECT3DBASETEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9)**

Pointer to an [**IDirect3DBaseTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9) interface that represents the texture object to filter.

*pPalette* \[out\]

Type: **const [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry)\***

Pointer to a [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry) structure that represents a 256-color palette to fill in, or **NULL** for nonpalettized formats. If a palette is not specified, the default Direct3D palette (an all opaque white palette) is provided. See Remarks.

*SrcLevel* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Level whose image is used to generate the subsequent levels. Specifying D3DX\_DEFAULT for this parameter is equivalent to specifying 0.

*MipFilter* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more [D3DX\_FILTER](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter) controlling how the mipmap is filtered. Specifying D3DX\_DEFAULT for this parameter is the equivalent of specifying D3DX\_FILTER\_BOX if the texture size is a power of two, and D3DX\_FILTER\_BOX \| D3DX\_FILTER\_DITHER otherwise.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA.

## Remarks

A filter is recursively applied to each texture level to generate the next texture level.

Writing to a non-level-zero surface of the texture will not cause the dirty rectangle to be updated. If **D3DXFilterTexture** is called and the surface was not already dirty (this is unlikely under normal usage scenarios), the application needs to explicitly call [**AddDirtyRect**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dtexture9-adddirtyrect) on the texture.

Textures created in the default pool (D3DPOOL\_DEFAULT) cannot be used with **D3DXFilterTexture** (unless created with D3DUSAGE\_DYNAMIC) because a lock operation is needed on the object. Note that locks are prohibited on textures in the default pool (unless they are dynamic).

For details on [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry), see the Platform SDK. Note that as of DirectX 8.0, the peFlags member of the **PALETTEENTRY** structure does not function as documented in the Platform SDK. The peFlags member is now the alpha channel for 8-bit palettized formats.

There is only one texture filtering function, but two macros that call this method.

```
#define D3DXFilterCubeTexture D3DXFilterTexture
#define D3DXFilterVolumeTexture D3DXFilterTexture
```

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

