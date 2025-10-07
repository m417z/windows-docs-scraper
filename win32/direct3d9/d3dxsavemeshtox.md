# D3DXSaveMeshToX function

Saves a mesh to a .x file.

## Parameters

*pFilename* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the filename. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks.

*pMesh* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Pointer to an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interface, representing the mesh to save to a .x file.

*pAdjacency* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of three DWORDs per face that specify the three neighbors for each face in the mesh. This parameter may be **NULL**.

*pMaterials* \[in\]

Type: **const [**D3DXMATERIAL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmaterial)\***

Pointer to an array of [**D3DXMATERIAL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmaterial) structures, containing material information to be saved in the .x file.

*pEffectInstances* \[in\]

Type: **const [**D3DXEFFECTINSTANCE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectinstance)\***

Pointer to an array of effect instances, one per attribute group in the mesh. This parameter may be **NULL**. An effect instance is a particular instance of state information used to initialize an effect. For more information, see [**D3DXEFFECTINSTANCE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectinstance).

*NumMaterials* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of [**D3DXMATERIAL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmaterial) structures in the *pMaterials* array.

*Format* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A combination of file format and save options when saving an .x file. See [D3DX X File Constants](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-x-file-constants).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXSaveMeshToXW. Otherwise, the function call resolves to D3DXSaveMeshToXA because ANSI strings are being used.

The default file format is binary; however, if a file is specified as both a binary and a text file, it will be saved as a text file. Regardless of the file format, you may also use the compressed format to reduce the file size.

The following is a typical code example of how to use this function.

```
ID3DXMesh*    m_pMesh;           // Mesh object to be saved to a .x file
D3DXMATERIAL* m_pMaterials;      // Array of material structs in the mesh
DWORD         m_dwNumMaterials;  // Number of material structs in the mesh

DWORD dwFormat = D3DXF_FILEFORMAT_BINARY;  // Binary-format .x file (default)
// DWORD dwFormat = D3DXF_FILEFORMAT_TEXT; // Text-format .x file

// Load mesh into m_pMesh and determine values of m_pMaterials and
// m_dwNumMaterials with calls to D3DXLoadMeshxxx or other D3DX functions

// ...

D3DXSaveMeshToX(
    L"outputxfilename.x",
    m_pMesh,
    NULL,
    m_pMaterials,
    NULL,
    m_dwNumMaterials,
    dwFormat );
```

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

[**D3DXEFFECTDEFAULT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectdefault)

[**D3DXEFFECTINSTANCE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectinstance)

