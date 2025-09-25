# IDirect3DDevice9::CreatePixelShader

## Description

Creates a pixel shader.

## Parameters

### `pFunction` [in]

Type: **const [DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the pixel shader function token array, specifying the blending operations. This value cannot be **NULL**.

### `ppShader` [out, retval]

Type: **[IDirect3DPixelShader9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dpixelshader9)****

Pointer to the returned pixel shader interface. See [IDirect3DPixelShader9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dpixelshader9).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL, D3DERR_OUTOFVIDEOMEMORY,
E_OUTOFMEMORY.

## See also

[D3DXAssembleShader](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxassembleshader)

[D3DXAssembleShaderFromFile](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxassembleshaderfromfile)

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)