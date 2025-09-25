# IDirect3DDevice9::CreateAdditionalSwapChain

## Description

Creates an additional swap chain for rendering multiple views.

## Parameters

### `pPresentationParameters` [in, out]

Type: **[D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters)***

Pointer to a [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters) structure, containing the presentation parameters for the new swap chain. This value cannot be **NULL**.

Calling this method changes the value of members of the D3DPRESENT_PARAMETERS structure.

* If BackBufferCount == 0, calling CreateAdditionalSwapChain will increase it to 1.
* If the application is in windowed mode, and if either the BackBufferWidth or the BackBufferHeight == 0, they will be set to the client area width and height of the hwnd.

### `pSwapChain` [out, retval]

Type: **[IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9)****

Address of a pointer to an [IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9) interface, representing the additional swap chain.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_NOTAVAILABLE, D3DERR_DEVICELOST, D3DERR_INVALIDCALL, D3DERR_OUTOFVIDEOMEMORY, E_OUTOFMEMORY.

## Remarks

There is always at least one swap chain (the implicit swap chain) for each device because Direct3D 9 has one swap chain as a property of the device.

Note that any given device can support only one full-screen swap chain.

D3DFMT_UNKNOWN can be specified for the windowed mode back buffer format when calling [IDirect3D9::CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice), [IDirect3DDevice9::Reset](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-reset) and CreateAdditionalSwapChain. This means the application does not have to query the current desktop format before calling CreateDevice for windowed mode. For full-screen mode, the back buffer format must be specified.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[Presenting Multiple Views in Windowed Mode (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/presenting-multiple-views-in-windowed-mode)