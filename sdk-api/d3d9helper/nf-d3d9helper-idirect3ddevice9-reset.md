# IDirect3DDevice9::Reset

## Description

Resets the type, size, and format of the swap chain.

## Parameters

### `pPresentationParameters` [in, out]

Type: **[D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters)***

Pointer to a [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters) structure, describing the new presentation parameters. This value cannot be **NULL**.

When switching to full-screen mode, Direct3D will try to find a desktop format that matches the back buffer format, so that back buffer and front buffer formats will be identical (to eliminate the need for color conversion).

When this method returns:

* BackBufferCount, BackBufferWidth, and BackBufferHeight are set to zero.
* BackBufferFormat is set to [D3DFMT_UNKNOWN](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) for windowed mode only; a full-screen mode must specify a format.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Possible return values include: D3D_OK, D3DERR_DEVICELOST, D3DERR_DEVICEREMOVED, D3DERR_DRIVERINTERNALERROR, or D3DERR_OUTOFVIDEOMEMORY (see [D3DERR](https://learn.microsoft.com/windows/desktop/direct3d9/d3derr)).

## Remarks

If a call to **IDirect3DDevice9::Reset** fails, the device will be placed in the "lost" state (as indicated by a return value of D3DERR_DEVICELOST from a call to [IDirect3DDevice9::TestCooperativeLevel](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-testcooperativelevel)) unless it is already in the "not reset" state (as indicated by a return value of D3DERR_DEVICENOTRESET from a call to **IDirect3DDevice9::TestCooperativeLevel**). Refer to **IDirect3DDevice9::TestCooperativeLevel** and [Lost Devices (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/lost-devices) for further information concerning the use of **IDirect3DDevice9::Reset** in the context of lost devices.

Calling **IDirect3DDevice9::Reset** causes all texture memory surfaces to be lost, managed textures to be flushed from video memory, and all state information to be lost. Before calling the **IDirect3DDevice9::Reset** method for a device, an application should release any explicit render targets, depth stencil surfaces, additional swap chains, state blocks, and D3DPOOL_DEFAULT resources associated with the device.

There are two different types of swap chains: full-screen or windowed. If the new swap chain is full-screen, the adapter will be placed in the display mode that matches the new size.

Direct3D 9 applications can expect messages to be sent to them during this call (for example, before this call is returned); applications should take precautions not to call into Direct3D at this time. In addition, when **IDirect3DDevice9::Reset** fails, the only valid methods that can be called are **IDirect3DDevice9::Reset**, [IDirect3DDevice9::TestCooperativeLevel](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-testcooperativelevel), and the various Release member functions. Calling any other method can result in an exception.

A call to **IDirect3DDevice9::Reset** will fail if called on a different thread than that used to create the device being reset.

Pixel shaders and vertex shaders survive **IDirect3DDevice9::Reset** calls for Direct3D 9. They do not need to be re-created explicitly by the application.

[D3DFMT_UNKNOWN](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) can be specified for the windowed mode back buffer format when calling [IDirect3D9::CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice), **IDirect3DDevice9::Reset**, and [IDirect3DDevice9::CreateAdditionalSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createadditionalswapchain). This means the application does not have to query the current desktop format before calling **IDirect3D9::CreateDevice** for windowed mode. For full-screen mode, the back buffer format must be specified. Setting BackBufferCount equal to zero (BackBufferCount = 0) results in one back buffer.

When trying to reset more than one display adapter in a group, set pPresentationParameters to point to an array of [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters) structures, one for each display in the adapter group.

If a multihead device was created with [D3DCREATE_ADAPTERGROUP_DEVICE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate), **IDirect3DDevice9::Reset** requires an array of [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters) structures wherein each structure must specify a full-screen display. To switch back to windowed mode, the application must destroy the device and re-create a non-multihead device in windowed mode.

## See also

[D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters)

[D3DSWAPEFFECT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dswapeffect)

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::Present](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-present)

[Multihead (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/multihead)