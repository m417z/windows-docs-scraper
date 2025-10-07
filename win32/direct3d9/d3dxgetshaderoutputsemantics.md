# D3DXGetShaderOutputSemantics function

Get the semantics for all shader output elements.

## Parameters

*pFunction* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the shader function DWORD stream.

*pSemantics* \[in\]

Type: **[**D3DXSEMANTIC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxsemantic)\***

Pointer to an array of [**D3DXSEMANTIC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxsemantic) structures. The function will fill this array with the semantics for each output element referenced by the shader. This array is assumed to contain at least MAXD3DDECLLENGTH elements. However, calling **D3DXGetShaderOutputSemantics** with pSemantics = **NULL** will return the number of elements needed for pCount.

*pCount* \[out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Returns the number of elements in pSemantics.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX9Shader.h |
| Library<br> | D3dx9.lib |

## See also

[Shader Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-shader)

