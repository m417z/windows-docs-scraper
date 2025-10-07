# D3DXConvertMeshSubsetToSingleStrip function

Converts the specified mesh subset into a single triangle strip.

## Parameters

*MeshIn* \[in\]

Type: **[**LPD3DXBASEMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh)**

Pointer to an [**ID3DXBaseMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh) interface, representing the mesh to convert to a strip.

*AttribId* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Attribute ID of the mesh subset to convert to strips.

*IBOptions* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more flags from the [**D3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmesh) enumeration, specifying options for creating the index buffer. Cannot be D3DXMESH\_32BIT. The index buffer will be created with 32-bit or 16-bit indices, depending on the format of the index buffer of the mesh specified by the *MeshIn* parameter.

*ppIndexBuffer* \[out\]

Type: **[**LPDIRECT3DINDEXBUFFER9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dindexbuffer9)\***

Pointer to an [**IDirect3DIndexBuffer9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dindexbuffer9) interface, representing the index buffer containing the strip.

*pNumIndices* \[out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Number of indices in the buffer returned in the *ppIndexBuffer* parameter.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following values: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

Before running this function, call [**Optimize**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh--optimize) or [**D3DXOptimizeFaces**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxoptimizefaces), with the D3DXMESHOPT\_ATTRSORT flag set.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

