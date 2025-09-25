# IDirect3DSwapChain9::GetBackBuffer

## Description

Retrieves a back buffer from the swap chain of the device.

## Parameters

### `iBackBuffer` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the back buffer object to return. Back buffers are numbered from 0 to the total number of back buffers - 1. A value of 0 returns the first back buffer, not the front buffer. The front buffer is not accessible through this method. Use [IDirect3DSwapChain9::GetFrontBufferData](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dswapchain9-getfrontbufferdata) to retrieve a copy of the front buffer.

### `Type` [in]

Type: **[D3DBACKBUFFER_TYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dbackbuffer-type)**

Stereo view is not supported in Direct3D 9, so the only valid value for this parameter is D3DBACKBUFFER_TYPE_MONO.

### `ppBackBuffer` [out, retval]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)****

Address of a pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface, representing the returned back buffer surface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.
If BackBuffer exceeds or equals the total number of back buffers, then the function fails and returns D3DERR_INVALIDCALL.

## Remarks

Calling this method will increase the internal reference count on the [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface. Failure to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when finished using this **IDirect3DSurface9** interface results in a memory leak. You must release any surfaces obtained through this method before releasing the swap chain it belongs to.

## See also

[IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9)

[IDirect3DSwapChain9::GetFrontBufferData](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dswapchain9-getfrontbufferdata)