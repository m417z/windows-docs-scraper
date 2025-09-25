# IDirect3DSwapChain9::GetFrontBufferData

## Description

Generates a copy of the swapchain's front buffer and places that copy in a system memory buffer provided by the application.

## Parameters

### `pDestSurface` [in, out]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

Pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface that will receive a copy of the swapchain's front buffer. The data is returned in successive rows with no intervening space, starting from the vertically highest row to the lowest. For windowed mode, the size of the destination surface should be the size of the desktop. For full screen mode, the size of the destination surface should be the screen size.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.
If BackBuffer exceeds or equals the total number of back buffers, the function fails and returns D3DERR_INVALIDCALL.

## Remarks

Calling this method will increase the internal reference count on the [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface. Failure to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when finished using this **IDirect3DSurface9** interface results in a memory leak.

## See also

[IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9)