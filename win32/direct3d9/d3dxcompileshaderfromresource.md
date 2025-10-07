# D3DXCompileShaderFromResource function

Compile a shader file.

> [!Note]
> Instead of using this legacy function, we recommend that you compile offline by using the Fxc.exe command-line compiler or use the [**D3DCompile**](https://learn.microsoft.com/windows/win32/api/d3dcompiler/nf-d3dcompiler-d3dcompile) API.

## Parameters

*hSrcModule* \[in\]

Type: **[**HMODULE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Handle to a module containing the effect description. If this parameter is **NULL**, the current module will be used.

*pSrcResource* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the resource name.

*pDefines* \[in\]

Type: **const [**D3DXMACRO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmacro)\***

An optional **NULL** terminated array of [**D3DXMACRO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmacro) structures. This value may be **NULL**.

*pInclude* \[in\]

Type: **[**LPD3DXINCLUDE**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxinclude)**

Optional interface pointer, [**ID3DXInclude**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxinclude), to use for handling \#include directives. If this value is **NULL**, \#includes will either be honored when compiling from a file, or will error when compiled from a resource or memory.

*pFunctionName* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to the shader entry point function where execution begins.

*pProfile* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a shader profile which determines the shader instruction set. See [**D3DXGetVertexShaderProfile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxgetvertexshaderprofile) or [**D3DXGetPixelShaderProfile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxgetpixelshaderprofile) for a list of the profiles available.

*Flags* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Compile options identified by various flags. The Direct3D 10 HLSL compiler is now the default. See [D3DXSHADER Flags](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-flags) for details.

*ppShader* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Returns a buffer containing the created shader. This buffer contains the compiled shader code, as well as any embedded debug and symbol table information.

*ppErrorMsgs* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Returns a buffer containing a listing of errors and warnings that were encountered during the compile. These are the same messages the debugger displays when running in debug mode. This value may be **NULL**.

*ppConstantTable* \[out\]

Type: **[**LPD3DXCONSTANTTABLE**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxconstanttable)\***

Returns an [**ID3DXConstantTable**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxconstanttable) interface, which can be used to access shader constants. This value can be **NULL**. If you compile your application as large address aware (that is, you use the /LARGEADDRESSAWARE linker option to handle addresses larger than 2 GB), you cannot use this parameter and must set it to **NULL**. Instead, you must use the [**D3DXGetShaderConstantTableEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxgetshaderconstanttableex) function to retrieve the shader-constant table that is embedded inside the shader. In this **D3DXGetShaderConstantTableEx** call, you must pass the **D3DXCONSTTABLE\_LARGEADDRESSAWARE** flag to the *Flags* parameter to specify to access up to 4 GB of virtual address space.

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

[**D3DXCompileShader**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcompileshader)

[**D3DXCompileShaderFromFile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcompileshaderfromfile)

