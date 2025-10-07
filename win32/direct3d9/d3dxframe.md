# D3DXFRAME structure

Encapsulates a transform frame in a transformation frame hierarchy.

## Members

**Name**

Type: **LPSTR**

Name of the frame.

**TransformationMatrix**

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)**

Transformation matrix.

**pMeshContainer**

Type: **[**LPD3DXMESHCONTAINER**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmeshcontainer)**

Pointer to the mesh container.

**pFrameSibling**

Type: ****D3DXFRAME**\***

Pointer to a sibling frame.

**pFrameFirstChild**

Type: ****D3DXFRAME**\***

Pointer to a child frame.

## Remarks

An application can derive from this structure to add other data.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

