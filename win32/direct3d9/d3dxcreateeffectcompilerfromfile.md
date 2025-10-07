# D3DXCreateEffectCompilerFromFile function

Creates an effect compiler from an ASCII effect description.

## Parameters

*pSrcFile* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to the filename. This parameter supports both Unicode and ANSI strings. See Remarks.

*pDefines* \[in\]

Type: **const [**D3DXMACRO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmacro)\***

An optional **NULL**-terminated array of [**D3DXMACRO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmacro) structures that describe preprocessor definitions. This value can be **NULL**.

*pInclude* \[in\]

Type: **[**LPD3DXINCLUDE**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxinclude)**

Optional interface pointer, [**ID3DXInclude**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxinclude), to use for handling \#include directives. If this value is **NULL**, \#includes will either be honored when compiling from a file or will cause an error when compiled from a resource or memory.

*Flags* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Compile options identified by various flags (see [D3DXSHADER Flags](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-flags)). The Direct3D 10 HLSL compiler is now the default. See [Effect-Compiler Tool](https://learn.microsoft.com/windows/win32/direct3dtools/fxc) for details.

*ppEffectCompiler* \[out\]

Type: **[**LPD3DXEFFECTCOMPILER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffectcompiler)\***

Address of a pointer to an [**ID3DXEffectCompiler**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffectcompiler) interface, containing the effect compiler.

*ppParseErrors* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Address of a pointer to an [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer) interface, containing any error messages that occurred during compilation. This parameter can be set to **NULL** to ignore error messages.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the LPCTSTR data type resolves to LPCSTR.

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXCreateEffectCompilerFromFileW. Otherwise, the function call resolves to D3DXCreateEffectCompilerFromFileA because ANSI strings are being used.

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX9Effect.h |
| Library<br> | D3dx9.lib |

## See also

[Effect Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-functions)

[**D3DXCreateEffectCompiler**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreateeffectcompiler)

[**D3DXCreateEffectCompilerFromResource**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreateeffectcompilerfromresource)

