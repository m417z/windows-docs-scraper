# D3DXFVFFromDeclarator function

Returns a flexible vertex format (FVF) code from a declarator.

## Parameters

*pDeclaration* \[in\]

Type: **const [**LPD3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9)\***

Array of [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9) elements, describing the FVF code.

*pFVF* \[out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to a DWORD value, representing the returned combination of [D3DFVF](https://learn.microsoft.com/windows/win32/direct3d9/d3dfvf) that describes the vertex format returned from the declarator.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be: D3DERR\_INVALIDCALL.

## Remarks

This function will fail for any declarator that does not map directly to an FVF.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

[**D3DXDeclaratorFromFVF**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxdeclaratorfromfvf)

