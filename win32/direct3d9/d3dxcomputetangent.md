# D3DXComputeTangent function

Computes the tangent vectors for the texture coordinates given in the texture stage. Provided to support legacy applications. Use [**D3DXComputeTangentFrameEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcomputetangentframeex) for better results.

## Parameters

*Mesh* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Pointer to an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interface that represent the input mesh.

*TexStageIndex* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Index that represents the texture stage.

*TangentIndex* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Index that provides the usage index for the tangent data. The vertex declaration implies the usage; this index modifies the usage with the usage index. For more information about a vertex declaration, see [Vertex Declaration (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/vertex-declaration).

*BinormIndex* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Index that provides the usage index for the binormal data. The vertex declaration implies the usage; this index modifies the usage with the usage index. For more information about a vertex declaration, see [Vertex Declaration (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/vertex-declaration).

*Wrap* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Set this value to 0 for no wrapping, or to 1 for wrapping in the U and V directions.

*pAdjacency* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of three DWORDs per face to be filled with adjacent face indices. The number of bytes in this array must be at least ((3 \* [**GetNumFaces**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh--getnumfaces)) \* sizeof(DWORD)).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is S\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

If the mesh vertex declaration specifies tangent or binormal fields, **D3DXComputeTangent** will update any user-supplied tangent or binormal data. Alternatively, set TangentIndex to [D3DX\_DEFAULT](https://learn.microsoft.com/windows/win32/direct3d9/other-d3dx-constants) to not update the user-supplied tangent data, or set BinormIndex to D3DX\_DEFAULT to not update the user-supplied binormal data. TexStageIndex cannot be set to D3DX\_DEFAULT.

**D3DXComputeTangent** depends on the mesh vertex declaration containing either the binormal field (BinormIndex), the tangent field (TangentIndex), or both. If both are missing, this function will fail.

This function simply calls [**D3DXComputeTangentFrameEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcomputetangentframeex) with the following input parameters:

```
D3DXComputeTangentFrameEx( Mesh,
                           D3DDECLUSAGE_TEXCOORD,
                           TexStageIndex,
                           ( BinormIndex == D3DX_DEFAULT ) ?
                               D3DX_DEFAULT : D3DDECLUSAGE_BINORMAL,
                               // provides backward function compatibility
                           BinormIndex,
                           ( TangentIndex == D3DX_DEFAULT ) ?
                               D3DX_DEFAULT : D3DDECLUSAGE_TANGENT,
                           TangentIndex,
                           D3DX_DEFAULT, // do not store normals
                           0,
                           ( Wrap ? D3DXTANGENT_WRAP_UV : 0 )
                               | D3DXTANGENT_GENERATE_IN_PLACE
                               | D3DXTANGENT_ORTHOGONALIZE_FROM_U,
                           pAdjacency,
                           -1.01f,
                           -0.01f,
                           -1.01f,
                           NULL,
                           NULL);
```

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

