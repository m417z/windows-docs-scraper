# D3DXComputeIMTFromTexture function

Calculates per-triangle IMT's from a texture mapped onto a mesh, to be used optionally as input to the D3DX [UVAtlas Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-uvatlas).

## Parameters

*pMesh* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

A pointer to an input mesh (see [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)) which contains the object geometry for calculating the IMT.

*pTexture* \[in\]

Type: **[**LPDIRECT3DTEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)**

A pointer to the texture (see [**IDirect3DTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)) that is mapped to the mesh.

*dwTextureIndex* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Zero-based texture coordinate index that identifies which set of texture coordinates to use.

*dwOptions* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Texture wrap options. This is a combination of one or more [**D3DXIMT FLAGS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximt-flags).

*pStatusCallback*

Type: **[LPD3DXUVATLASCB](https://learn.microsoft.com/windows/win32/direct3d9/lpd3dxuvatlascb)**

A pointer to a callback function to monitor IMT computation progress.

*pUserContext*

Type: **[**LPVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A pointer to a user-defined variable which is passed to the status callback function. Typically used by an application to pass a pointer to a data structure that provides context information for the callback function.

*ppIMTData* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

A pointer to the buffer (see [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)) containing the returned IMT array. This array can be provided as input to the D3DX [UVAtlas Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-uvatlas) to prioritize texture-space allocation in the texture parameterization.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK; otherwise, the value is D3DERR\_INVALIDCALL.

## Remarks

Given a texture that maps over the surface of the mesh, the algorithm computes the IMT for each face. This will cause triangles containing lower-frequency signal data to take up less space in the final texture atlas when parameterized with the UVAtlas functions. The texture is assumed to be interpolated over the mesh bilinearly.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[UVAtlas Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-uvatlas)

[Using UVAtlas (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/using-uvatlas)

