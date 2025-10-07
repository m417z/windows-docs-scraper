# D3DXSHPRTSPLITMESHVERTDATA structure

## Members

**uVertRemap**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Vertex in original mesh this corresponds to.

**uSubCluster**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Cluster index, relative to the supercluster.

**ucVertStatus**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

1 if vertex has valid data, 0 if it is "full".

## Remarks

Allocated in [**D3DXSHPRTCompSplitMeshSC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshprtcompsplitmeshsc).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

