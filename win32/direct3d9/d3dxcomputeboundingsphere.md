# D3DXComputeBoundingSphere function (D3DX9Mesh.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Computes a bounding sphere for the mesh.

## Parameters

*pFirstPosition* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to first position.

*NumVertices* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of vertices.

*dwStride* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of bytes between position vectors. Use [**GetNumBytesPerVertex**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh--getnumbytespervertex), [**D3DXGetFVFVertexSize**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxgetfvfvertexsize), or [**D3DXGetDeclVertexSize**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxgetdeclvertexsize) to get the vertex stride.

*pCenter* \[out\]

Type: **[**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

[**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, defining the coordinate center of the returned bounding sphere.

*pRadius* \[out\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Radius of the returned bounding sphere.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

