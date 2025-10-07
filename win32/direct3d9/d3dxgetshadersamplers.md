# D3DXGetShaderSamplers function

Get the sampler names referenced in a shader.

## Parameters

*pFunction* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the shader function DWORD stream.

*pSamplers* \[in, out\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of LPCSTRs. The function will fill this array with pointers to the sampler names contained within *pFunction*. The maximum array size is the maximum number of sampler registers (16 for vs\_3\_0 and ps\_3\_0).

To find the number of samplers used, check *pCount* after calling **D3DXGetShaderSamplers** with pSamplers = **NULL**.

*pCount* \[out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Returns the number of samplers referenced by the shader.

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

