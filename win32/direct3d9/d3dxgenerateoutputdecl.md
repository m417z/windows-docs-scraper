# D3DXGenerateOutputDecl function

Generates an output vertex declaration from the input declaration. The output declaration is intended for use by the mesh tessellation functions.

## Parameters

*pOutput* \[out\]

Type: **[**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9)\***

Pointer to the output vertex declaration. See [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9).

*pInput* \[in\]

Type: **const [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9)\***

Pointer to the input vertex declaration. See [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following values: D3DERR\_INVALIDCALL.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

