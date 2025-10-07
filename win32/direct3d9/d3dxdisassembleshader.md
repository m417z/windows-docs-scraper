# D3DXDisassembleShader function

Disassemble a shader.

> [!Note]
> Instead of using this legacy function, we recommend that you use the [**D3DDisassemble**](https://learn.microsoft.com/windows/win32/api/d3dcompiler/nf-d3dcompiler-d3ddisassemble) API.

## Parameters

*pShader* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to a memory buffer that contains the shader data.

*EnableColorCode* \[in\]

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Enable color code to make it easier to read the disassembly.

*pComments* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

An optional NULL-terminated comment string. This value may be **NULL**.

*ppDisassembly* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Returns a buffer containing the disassembled shader. See [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer).

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

