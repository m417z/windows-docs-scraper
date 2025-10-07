# D3DXLoadMeshFromX function

Loads a mesh from a DirectX .x file.

## Parameters

*pFilename* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the filename. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks.

*Options* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more flags from the [**D3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmesh) enumeration, which specifies creation options for the mesh.

*pD3DDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, the device object associated with the mesh.

*ppAdjacency* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Pointer to a buffer that contains adjacency data. The adjacency data contains an array of three DWORDs per face that specify the three neighbors for each face in the mesh. For more information about accessing the buffer, see [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer).

*ppMaterials* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Pointer to a buffer containing materials data. The buffer contains an array of [**D3DXMATERIAL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmaterial) structures, containing information from the DirectX file. For more information about accessing the buffer, see [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer).

*ppEffectInstances* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Pointer to a buffer containing an array of effect instances, one per attribute group in the returned mesh. An effect instance is a particular instance of state information used to initialize an effect. See [**D3DXEFFECTINSTANCE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectinstance). For more information about accessing the buffer, see [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer).

*pNumMaterials* \[out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the number of [**D3DXMATERIAL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmaterial) structures in the *ppMaterials* array, when the method returns.

*ppMesh* \[out\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)\***

Address of a pointer to an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interface, representing the loaded mesh.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following values: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXLoadMeshFromXW. Otherwise, the function call resolves to D3DXLoadMeshFromXA because ANSI strings are being used.

All the meshes in the file will be collapsed into one output mesh. If the file contains a frame hierarchy, all the transformations will be applied to the mesh.

For mesh files that do not contain effect instance information, default effect instances will be generated from the material information in the .x file. A default effect instance will have default values that correspond to the members of the [**D3DMATERIAL9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmaterial9) structure.

The default texture name is also filled in, but is handled differently. The name will be Texture0@Name, which corresponds to an effect variable by the name of "Texture0" with an annotation called "Name." This will contain the string file name for the texture.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

[**D3DXEFFECTDEFAULT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectdefault)

[**D3DXEFFECTINSTANCE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectinstance)

