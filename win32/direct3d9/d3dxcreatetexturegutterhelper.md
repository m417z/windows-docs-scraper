# D3DXCreateTextureGutterHelper function

Creates an [**ID3DXTextureGutterHelper**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxtexturegutterhelper) object from an input mesh and texture data.

## Parameters

*Width* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of the texture, in pixels.

*Height* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height of the texture, in pixels.

*pMesh* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Pointer to an input [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) mesh object.

*GutterSize* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of texels by which to over-sample the texture and create the gutter region. Must be at least 1.

*ppBuffer* \[in, out\]

Type: **[**LPD3DXTEXTUREGUTTERHELPER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxtexturegutterhelper)\***

Pointer to an [**ID3DXTextureGutterHelper**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxtexturegutterhelper) object to be created.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is S\_OK. If the function fails, the return value can be one of these: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

Use [**D3DXConcatenateMeshes**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxconcatenatemeshes) to transform a scene to new coordinates.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Precomputed Radiance Transfer Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-prt)

