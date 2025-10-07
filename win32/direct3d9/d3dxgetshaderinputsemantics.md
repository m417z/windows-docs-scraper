# D3DXGetShaderInputSemantics function

Gets the semantics for the shader inputs. Use this method to determine the input vertex format.

## Parameters

*pFunction* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the shader function DWORD stream.

*pSemantics* \[in\]

Type: **[**D3DXSEMANTIC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxsemantic)\***

Pointer to an array of [**D3DXSEMANTIC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxsemantic) structures. The function will fill this array with the semantics for each input element referenced by the shader. This array is assumed to contain at least MAXD3DDECLLENGTH elements. However, calling **D3DXGetShaderInputSemantics** with pSemantics = **NULL** will return the number of elements needed for pCount.

*pCount* \[out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Returns the number of elements in pSemantics.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

Use **D3DXGetShaderInputSemantics** to return a list of input semantics required by the shader. This is the way to find out what the input vertex format is for a high-level shader language (HLSL) shader. If the shader has additional inputs that your vertex declaration is missing, you could create an extra vertex stream that has a stride of 0 that has the missing components with default values. For instance, this technique could be used to provide default vertex color for models that do not specify it.

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX9Shader.h |
| Library<br> | D3dx9.lib |

## See also

[Shader Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-shader)

