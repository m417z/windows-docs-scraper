# IDirect3DDevice9::GetPixelShader

## Description

Retrieves the currently set pixel shader.

## Parameters

### `ppShader` [out, retval]

Type: **[IDirect3DPixelShader9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dpixelshader9)****

Pointer to a pixel shader interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

This method will not work on a device that is created using D3DCREATE_PUREDEVICE.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetPixelShader](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setpixelshader)