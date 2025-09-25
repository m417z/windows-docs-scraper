# IDirect3DDevice9::GetDepthStencilSurface

## Description

Gets the depth-stencil surface owned by the Direct3DDevice object.

## Parameters

### `ppZStencilSurface` [out, retval]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)****

Address of a pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface, representing the returned depth-stencil surface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.If the device doesn't have a depth stencil buffer associated with it, the return value will be D3DERR_NOTFOUND. Otherwise, if the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

Calling this method will increase the internal reference count on the [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface. Failure to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when finished using this **IDirect3DSurface9** interface results in a memory leak.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetDepthStencilSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setdepthstencilsurface)