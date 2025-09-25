# IDirect3DSwapChain9::GetDevice

## Description

Retrieves the device associated with the swap chain.

## Parameters

### `ppDevice` [out, retval]

Type: **[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)****

Address of a pointer to an [IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface to fill with the device pointer, if the query succeeds.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

This method allows navigation to the owning device object.

Calling this method will increase the internal reference count on the [IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface. Failure to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when finished using this **IDirect3DDevice9** interface results in a memory leak.

## See also

[IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9)