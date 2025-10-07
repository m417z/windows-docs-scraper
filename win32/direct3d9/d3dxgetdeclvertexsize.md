# D3DXGetDeclVertexSize function

Returns the size of a vertex from the vertex declaration.

## Parameters

*pDecl* \[in\]

Type: **const [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9)\***

A pointer to the vertex declaration. See [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9).

*Stream* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The zero-based stream index.

## Return value

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The vertex declaration size, in bytes.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

