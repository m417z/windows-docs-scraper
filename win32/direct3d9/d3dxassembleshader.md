# D3DXAssembleShader function

Assemble a shader.

## Parameters

*pSrcData* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a memory buffer that contains the shader data.

*SrcDataLen* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Length of the effect data, in bytes.

*pDefines* \[in\]

Type: **const [**D3DXMACRO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmacro)\***

An optional **NULL** terminated array of [**D3DXMACRO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmacro) structures. This value may be **NULL**.

*pInclude* \[in\]

Type: **[**LPD3DXINCLUDE**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxinclude)**

Optional interface pointer, [**ID3DXInclude**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxinclude), to use for handling \#include directives. If this value is **NULL**, \#includes will either be honored when compiling from a file or will cause an error when compiled from a resource or memory.

*Flags* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Compile options identified by various flags. The Direct3D 10 HLSL compiler is now the default. See [D3DXSHADER Flags](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-flags) for details.

*ppShader* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Returns a buffer containing the created shader. This buffer contains the compiled shader code, as well as any embedded debug and symbol table information.

*ppErrorMsgs* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Returns a buffer containing a listing of errors and warnings that were encountered during the compile. These are the same messages the debugger displays when running in debug mode. This value may be **NULL**.

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

[**D3DXAssembleShaderFromFile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxassembleshaderfromfile)

[**D3DXAssembleShaderFromResource**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxassembleshaderfromresource)

