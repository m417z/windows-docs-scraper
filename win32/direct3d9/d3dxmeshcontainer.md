# D3DXMESHCONTAINER structure

Encapsulates a mesh object in a transformation frame hierarchy.

## Members

**Name**

Type: **LPSTR**

Mesh name.

**MeshData**

Type: **[**D3DXMESHDATA**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmeshdata)**

Type of data in the mesh. See [**D3DXMESHDATA**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmeshdata).

**pMaterials**

Type: **[**LPD3DXMATERIAL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmaterial)**

Array of mesh materials. See [**D3DXMATERIAL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmaterial).

**pEffects**

Type: **[**LPD3DXEFFECTINSTANCE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectinstance)**

Pointer to a set of default effect parameters. See [**D3DXEFFECTINSTANCE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectinstance).

**NumMaterials**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of materials in the mesh.

**pAdjacency**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of three DWORDs per triangle of the mesh that contains adjacency information.

**pSkinInfo**

Type: **[**LPD3DXSKININFO**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo)**

Pointer to the skin information interface. See [**ID3DXSkinInfo**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo).

**pNextMeshContainer**

Type: ****D3DXMESHCONTAINER**\***

Pointer to the next mesh container.

## Remarks

An application can derive from this structure to add other data.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

