# D3DXComputeNormalMap function

Converts a height map into a normal map. The (x,y,z) components of each normal are mapped to the (r,g,b) channels of the output texture.

## Parameters

*pTexture* \[out\]

Type: **[**LPDIRECT3DTEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)**

Pointer to an [**IDirect3DTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9) interface, representing the destination texture.

*pSrcTexture* \[in\]

Type: **[**LPDIRECT3DTEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)**

Pointer to an [**IDirect3DTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9) interface, representing the source height-map texture.

*pSrcPalette* \[in\]

Type: **const [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry)\***

Pointer to a [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry) type that contains the source palette of 256 colors or **NULL**.

*Flags* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

One or more [D3DX\_NORMALMAP](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-normalmap) flags that control generation of normal maps.

*Channel* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

One [D3DX\_CHANNEL](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-channel) flag specifying the source of height information.

*Amplitude* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Constant value multiplier that increases (or decreases) the values in the normal map. Higher values usually make bumps more visible, lower values usually make bumps less visible.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be the following value: D3DERR\_INVALIDCALL.

## Remarks

This method computes the normal by using the central difference with a kernel size of 3x3. The central differencing denominator used is 2.0. RGB channels in the destination contain biased (x,y,z) components of the normal.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

