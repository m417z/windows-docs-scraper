# D3DXCreateEffectEx function

Creates an effect from an ASCII or binary effect description. This function is an extended version of [**D3DXCreateEffect**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreateeffect) that allows an application to control which parameters are ignored by the effects system.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to the device that will create the effect. See [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9).

*pSrcData* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a buffer containing an effect description.

*SrcDataLen* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Length of the effect data, in bytes.

*pDefines* \[in\]

Type: **const [**D3DXMACRO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmacro)\***

An optional **NULL**-terminated array of [**D3DXMACRO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmacro) structures that describe preprocessor definitions. This value can be **NULL**.

*pInclude* \[in\]

Type: **[**LPD3DXINCLUDE**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxinclude)**

Optional interface pointer, [**ID3DXInclude**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxinclude), to use for handling \#include directives. If this value is **NULL**, \#includes will either be honored when compiling from a file or will cause an error when compiled from a resource or memory.

*pSkipConstants* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A string of effect parameters that will be ignored by the effect system. The string must be **NULL** terminated, and needs to contain the name of each application-managed constant separated by a semicolon.

*Flags* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If *pSrcData* contains a text effect, flags can be a combination of [D3DXSHADER Flags](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-flags) and [D3DXFX](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfx) flags; otherwise, *pSrcData* contains a binary effect and the only flags honored are D3DXFX flags. The Direct3D 10 HLSL compiler is now the default. See [Effect-Compiler Tool](https://learn.microsoft.com/windows/win32/direct3dtools/fxc) for details.

*pPool* \[in\]

Type: **[**LPD3DXEFFECTPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffectpool)**

Pointer to an [**ID3DXEffectPool**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffectpool) object to use for shared parameters. If this value is **NULL**, no parameters will be shared.

*ppEffect* \[out\]

Type: **[**LPD3DXEFFECT**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffect)\***

Returns a pointer to an [**ID3DXEffect**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffect) interface.

*ppCompilationErrors* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Returns a buffer containing a list of compile errors.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

This function is an extended version of [**D3DXCreateEffect**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreateeffect) that allows an application to specify which effect constants will be managed by the application. A constant that is managed by the application is ignored by the effects system. That is, the application is responsible for initializing the constant as well as saving and restoring its state whenever appropriate.

This function checks each constant in pSkipConstants to see that:

- It is bound to a constant register.
- It is only used in HLSL shader code.

If a constant is named in the string that is not present in the effect, it is ignored.

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX9Effect.h |
| Library<br> | D3dx9.lib |

## See also

[Effect Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-functions)

[**D3DXCreateEffectFromFileEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreateeffectfromfileex)

[**D3DXCreateEffectFromResourceEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreateeffectfromresourceex)

