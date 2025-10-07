# D3DXCreateEffectFromFile function

Create an effect from an ASCII or binary effect description.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to the device that will create the effect. See [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9).

*pSrcFile* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to the filename. This parameter supports both Unicode and ANSI strings. See Remarks.

*pDefines* \[in\]

Type: **const [**D3DXMACRO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmacro)\***

Optional NULL-terminated array of preprocessor macro definitions. See [**D3DXMACRO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmacro).

*pInclude* \[in\]

Type: **[**LPD3DXINCLUDE**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxinclude)**

Optional interface pointer, [**ID3DXInclude**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxinclude), to use for handling \#include directives. If this value is **NULL**, \#includes will either be honored when compiling from a file or will cause an error when compiled from a resource or memory.

*Flags* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If *pSrcFile* contains a text effect, flags can be a combination of [D3DXSHADER Flags](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-flags) and [D3DXFX](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfx) flags; otherwise, *pSrcFile* contains a binary effect and the only flags honored are D3DXFX flags. The Direct3D 10 HLSL compiler is now the default. See [Effect-Compiler Tool](https://learn.microsoft.com/windows/win32/direct3dtools/fxc) for details.

*pPool* \[in\]

Type: **[**LPD3DXEFFECTPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffectpool)**

Pointer to a [**ID3DXEffectPool**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffectpool) object to use for shared parameters. If this value is **NULL**, no parameters will be shared.

*ppEffect* \[out\]

Type: **[**LPD3DXEFFECT**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffect)\***

Returns a pointer to a buffer containing the compiled effect. See [**ID3DXEffect**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffect).

*ppCompilationErrors* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Returns a pointer to a buffer containing a listing of compile errors. See [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the LPCTSTR data type resolves to LPCSTR.

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXCreateEffectFromFileW. Otherwise, the function call resolves to D3DXCreateEffectFromFileA because ANSI strings are being used.

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX9Effect.h |
| Library<br> | D3dx9.lib |

## See also

[Effect Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-functions)

[**D3DXCompileShader**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcompileshader)

[**D3DXCompileShaderFromResource**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcompileshaderfromresource)

