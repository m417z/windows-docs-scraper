# D3DXLoadSkinMeshFromXof function

Loads a skin mesh from a DirectX .x file data object.

## Parameters

*pxofMesh* \[in\]

Type: **[**LPD3DXFILEDATA**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfiledata)**

Pointer to an [**ID3DXFileData**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfiledata) interface, representing the file data object to load.

*Options* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more flags, from the [**D3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmesh) enumeration, specifying creation options for the mesh.

*pD3DDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, the device object associated with the mesh.

*ppAdjacency* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Address of a pointer to an [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer) interface. When this method returns, this parameter is filled with an array of three DWORDs per face that specify the three neighbors for each face in the mesh.

*ppMaterials* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Address of a pointer to an [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer) interface. When the method returns, this parameter is filled with an array of [**D3DXMATERIAL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmaterial) structures.

*ppEffectInstances* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Pointer to a buffer containing an array of effect instances, one per attribute group in the returned mesh. An effect instance is a particular instance of state information used to initialize an effect. See [**D3DXEFFECTINSTANCE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectinstance). For more information about accessing the buffer, see [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer).

*pMatOut* \[out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the number of [**D3DXMATERIAL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmaterial) structures in the *ppMaterials* array, when the method returns.

*ppSkinInfo* \[out\]

Type: **[**LPD3DXSKININFO**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo)\***

Address of a pointer to an [**ID3DXSkinInfo**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo) interface, which represents the skinning information.

*ppMesh* \[out\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)\***

Address of a pointer to an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interface, which represents the loaded mesh.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY

## Remarks

This method takes a pointer to an internal object in the .x file, enabling you to load the frame hierarchy.

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

