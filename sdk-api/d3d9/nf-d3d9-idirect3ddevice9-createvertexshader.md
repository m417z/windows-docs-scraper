# IDirect3DDevice9::CreateVertexShader

## Description

Creates a vertex shader.

## Parameters

### `pFunction` [in]

Type: **const [DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to an array of tokens that represents the vertex shader, including any embedded debug and symbol table information.

* Use a function such as [D3DXCompileShader](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcompileshader) to create the array from a HLSL shader.
* Use a function like [D3DXAssembleShader](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxassembleshader) to create the token array from an assembly language shader.
* Use a function like [ID3DXEffectCompiler::CompileShader](https://learn.microsoft.com/windows/desktop/direct3d9/id3dxeffectcompiler--compileshader) to create the array from an effect.

### `ppShader` [out, retval]

Type: **[IDirect3DVertexShader9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexshader9)****

Pointer to the returned vertex shader interface (see [IDirect3DVertexShader9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexshader9)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL, D3DERR_OUTOFVIDEOMEMORY, E_OUTOFMEMORY.

## Remarks

When a device is created, [IDirect3D9::CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice) uses the behavior flag to determine whether to process vertices in hardware or software. There are three possibilities:

* Process vertices in hardware by setting D3DCREATE_HARDWARE_VERTEXPROCESSING.
* Process vertices in software by setting D3DCREATE_SOFTWARE_VERTEXPROCESSING.
* Process vertices in either hardware or software by setting D3DCREATE_MIXED_VERTEXPROCESSING. To switch a mixed-mode device between software and hardware processing, use [IDirect3DDevice9::SetSoftwareVertexProcessing](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setsoftwarevertexprocessing).

For an example using [D3DXCompileShader](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcompileshader), see [HLSLwithoutEffects Sample](https://msdn.microsoft.com/library/Ee417786(v=VS.85).aspx).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)