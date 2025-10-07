# D3DXMATERIAL structure

Returns material information saved in Direct3D (.x) files.

## Members

**MatD3D**

Type: **[**D3DMATERIAL9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmaterial9)**

[**D3DMATERIAL9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmaterial9) structure that describes the material properties.

**pTextureFilename**

Type: **LPSTR**

Pointer to a string that specifies the file name of the texture.

## Remarks

The [**D3DXLoadMeshFromX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxloadmeshfromx) and [**D3DXLoadMeshFromXof**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxloadmeshfromxof) functions return an array of **D3DXMATERIAL** structures that specify the material color and name of the texture for each material in the mesh. The application is then required to load the texture.

The LPD3DXMATERIAL type is defined as a pointer to the **D3DXMATERIAL** structure.

```
typedef struct D3DXMATERIAL* LPD3DXMATERIAL;
```

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

[**D3DXLoadMeshFromX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxloadmeshfromx)

[**D3DXLoadMeshFromXof**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxloadmeshfromxof)

