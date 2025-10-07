# D3DXUVAtlasPack function

Pack mesh partitioning data into an atlas.

## Parameters

*pMesh* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Pointer to an input mesh (see [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)) which contains the object geometry for calculating the atlas. At a minimum, the mesh must contain position data and 2D texture coordinates.

*dwWidth* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Texture width.

*dwHeight* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Texture height.

*fGutter* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The minimum distance, in texels, between two charts on the atlas. The gutter is always scaled by the width; so, if a gutter of 2.5 is used on a 512x512 texture, then the minimum distance between two charts is 2.5 / 512.0 texels.

*dwTextureIndex* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Zero-based texture coordinate index that identifies which set of texture coordinates to use.

*pdwPartitionResultAdjacency*

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of three DWORDs per face that specify the three neighbors for each face in the mesh. It should be derived from the ppPartitionResultAdjacency returned from [**D3DXUVAtlasPartition**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxuvatlaspartition). This value cannot be **NULL**, because Pack needs to know where charts were cut in the partition step in order to find the edges of each chart.

*pCallback* \[in\]

Type: **[LPD3DXUVATLASCB](https://learn.microsoft.com/windows/win32/direct3d9/lpd3dxuvatlascb)**

A pointer to a callback function (see [LPD3DXUVATLASCB](https://learn.microsoft.com/windows/win32/direct3d9/lpd3dxuvatlascb)) that is useful for monitoring progress.

*fCallbackFrequency* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specify how often D3DX will call the callback; a reasonable default value is 0.0001f.

*pUserContent* \[in\]

Type: **[**LPVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A void pointer to be passed back to the callback function.

*dwOptions* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

This options parameter is currently reserved.

*pFacePartitioning* \[in\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)**

A pointer to an [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer) containing the array of the final face-partitioning. Each element contains one DWORD per face.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK; otherwise, the value is D3DERR\_INVALIDCALL.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[UVAtlas Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-uvatlas)

