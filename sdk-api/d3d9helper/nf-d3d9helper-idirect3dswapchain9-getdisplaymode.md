# IDirect3DSwapChain9::GetDisplayMode

## Description

Retrieves the display mode's spatial resolution, color resolution, and refresh frequency.

## Parameters

### `pMode` [out]

Type: **[D3DDISPLAYMODE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymode)***

Pointer to a [D3DDISPLAYMODE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymode) structure containing data about the display mode of the adapter. As opposed to the display mode of the device, which may not be active if the device does not own full-screen mode.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## See also

[IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9)