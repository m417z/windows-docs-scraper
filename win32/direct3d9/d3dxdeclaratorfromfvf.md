# D3DXDeclaratorFromFVF function

Returns a declarator from a flexible vertex format (FVF) code.

## Parameters

*FVF* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of [D3DFVF](https://learn.microsoft.com/windows/win32/direct3d9/d3dfvf) that describes the FVF from which to generate the returned declarator array.

*Declaration* \[in, out\]

Type: **[**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9)**

An array of [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9) elements describing the vertex format of the mesh vertices. The upper limit of this declarator array is [**MAX\_FVF\_DECL\_SIZE**](https://learn.microsoft.com/windows/win32/direct3d9/max-fvf-decl-size).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DXERR\_INVALIDMESH.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

[**D3DXFVFFromDeclarator**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfvffromdeclarator)

