# D3DXLoadVolumeFromMemory function

Loads a volume from memory.

## Parameters

*pDestVolume* \[in\]

Type: **[**LPDIRECT3DVOLUME9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolume9)**

Pointer to an [**IDirect3DVolume9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolume9) interface. Specifies the destination volume, which receives the image.

*pDestPalette* \[in\]

Type: **const [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry)\***

Pointer to a [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry) structure, the destination palette of 256 colors or **NULL**.

*pDestBox* \[in\]

Type: **const [**D3DBOX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbox)\***

Pointer to a [**D3DBOX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbox) structure. Specifies the destination box. Set this parameter to **NULL** to specify the entire volume.

*pSrcMemory* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to the top-left corner of the source volume in memory.

*SrcFormat* \[in\]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, the pixel format of the source volume.

*SrcRowPitch* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pitch of source image, in bytes. For DXT formats (compressed texture formats), this number should represent the size of one row of cells, in bytes.

*SrcSlicePitch* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pitch of source image, in bytes. For DXT formats (compressed texture formats), this number should represent the size of one slice of cells, in bytes.

*pSrcPalette* \[in\]

Type: **const [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry)\***

Pointer to a [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry) structure, the source palette of 256 colors or **NULL**.

*pSrcBox* \[in\]

Type: **const [**D3DBOX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbox)\***

Pointer to a [**D3DBOX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbox) structure. Specifies the source box. **NULL** is not a valid value for this parameter.

*Filter* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A combination of one or more [D3DX\_FILTER](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter) controlling how the image is filtered. Specifying D3DX\_DEFAULT for this parameter is the equivalent of specifying D3DX\_FILTER\_TRIANGLE \| D3DX\_FILTER\_DITHER.

*ColorKey* \[in\]

Type: **[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor)**

[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor) value to replace with transparent black, or 0 to disable the colorkey. This is always a 32-bit ARGB color, independent of the source image format. Alpha is significant and should usually be set to FF for opaque color keys. Thus, for opaque black, the value would be equal to 0xFF000000.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following values: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA.

## Remarks

Writing to a non-level-zero surface of the volume texture will not cause the dirty rectangle to be updated. If **D3DXLoadVolumeFromMemory** is called and the texture was not already dirty (this is unlikely under normal usage scenarios), the application needs to explicitly call [**IDirect3DVolumeTexture9::AddDirtyBox**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dvolumetexture9-adddirtybox) on the volume texture.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[**D3DXLoadVolumeFromFile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxloadvolumefromfile)

[**D3DXLoadVolumeFromResource**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxloadvolumefromresource)

[**D3DXLoadVolumeFromVolume**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxloadvolumefromvolume)

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

