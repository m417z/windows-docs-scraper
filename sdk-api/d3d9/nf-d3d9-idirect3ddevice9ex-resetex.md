# IDirect3DDevice9Ex::ResetEx

## Description

Resets the type, size, and format of the swap chain with all other surfaces persistent.

## Parameters

### `pPresentationParameters` [in, out]

Type: **[D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters)***

Pointer to a [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters) structure, describing the new presentation parameters. This value cannot be **NULL**.

When switching to full-screen mode, Direct3D will try to find a desktop format that matches the back buffer format, so that back buffer and front buffer formats will be identical (to eliminate the need for color conversion).

When this method returns:

* BackBufferCount, BackBufferWidth, and BackBufferHeight are set to zero.
* BackBufferFormat is set to [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) for windowed mode only; a full-screen mode must specify a format.

### `pFullscreenDisplayMode` [in, out]

Type: **[D3DDISPLAYMODEEX](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodeex)***

Pointer to a [D3DDISPLAYMODEEX](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodeex) structure that describes the properties of the desired display mode. This value must be provided for fullscreen applications, but can be **NULL** for windowed applications.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

The method can return: D3D_OK, D3DERR_DEVICELOST or D3DERR_DEVICEHUNG (see [D3DERR](https://learn.microsoft.com/windows/desktop/direct3d9/d3derr)).

If this method returns D3DERR_DEVICELOST or D3DERR_DEVICEHUNG then the application can only call **IDirect3DDevice9Ex::ResetEx**, [IDirect3DDevice9Ex::CheckDeviceState](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-checkdevicestate) or release the interface pointer; any other API call will cause an exception.

## Remarks

If a call to **IDirect3DDevice9Ex::ResetEx** fails, the device will be placed in the lost state (as indicated by a return value of D3DERR_DEVICELOST from a call to [IDirect3DDevice9Ex::CheckDeviceState](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-checkdevicestate)). Refer to **IDirect3DDevice9Ex::CheckDeviceState** and [Lost Device Behavior Changes](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh) for further information concerning the use of **IDirect3DDevice9Ex::ResetEx** in the context of lost devices.

Unlike previous versions of DirectX, calling **IDirect3DDevice9Ex::ResetEx** does not cause surfaces, textures or state information to be lost.

Pixel shaders and vertex shaders survive **IDirect3DDevice9Ex::ResetEx** calls for Direct3D 9. They do not need to be re-created explicitly by the application.

There are two different types of swap chains: full-screen or windowed. If the new swap chain is full-screen, the adapter will be placed in the display mode that matches the new size.

Applications can expect messages to be sent to them during this call (for example, before this call is returned); applications should take precautions not to call into Direct3D at this time.

A call to **IDirect3DDevice9Ex::ResetEx** will fail if called on a different thread than that used to create the device being reset.

D3DFMT_UNKNOWN can be specified for the windowed mode back buffer format when calling [IDirect3D9Ex::CreateDeviceEx](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9ex-createdeviceex), **IDirect3DDevice9Ex::ResetEx**, and [IDirect3DDevice9::CreateAdditionalSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createadditionalswapchain). This means the application does not have to query the current desktop format before calling **IDirect3D9Ex::CreateDeviceEx** for windowed mode. For full-screen mode, the back buffer format must be specified. Setting BackBufferCount equal to zero (BackBufferCount = 0) results in one back buffer.

When trying to reset more than one display adapter in a group, set pPresentationParameters to point to an array of [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters) structures, one for each display in the adapter group.

If a multihead device was created with [D3DCREATE_ADAPTERGROUP_DEVICE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate), **IDirect3DDevice9Ex::ResetEx** requires an array of [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters) structures wherein each structure must specify a full-screen display. To switch back to windowed mode, the application must destroy the device and re-create a non-multihead device in windowed mode.

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)