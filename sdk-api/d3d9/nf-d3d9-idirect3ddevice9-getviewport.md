# IDirect3DDevice9::GetViewport

## Description

Retrieves the viewport parameters currently set for the device.

## Parameters

### `pViewport` [out]

Type: **[D3DVIEWPORT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dviewport9)***

Pointer to a [D3DVIEWPORT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dviewport9) structure, representing the returned viewport parameters.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if the pViewport parameter is invalid.

## Remarks

Typically, methods that return state will not work on a device that is created using D3DCREATE_PUREDEVICE. This method however, will work even on a pure device.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetViewport](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setviewport)