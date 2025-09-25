# IDirect3DDevice9::GetVertexShader

## Description

Retrieves the currently set vertex shader.

## Parameters

### `ppShader` [out, retval]

Type: **[IDirect3DVertexShader9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexshader9)****

Pointer to a vertex shader interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.
If ppShader is invalid, D3DERR_INVALIDCALL is returned.

## Remarks

Typically, methods that return state will not work on a device that is created using D3DCREATE_PUREDEVICE. This method however, will work even on a pure device because it returns an interface.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetVertexShader](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setvertexshader)