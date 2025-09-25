# IDirect3D9::CreateDevice

## Description

Creates a device to represent the display adapter.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number that denotes the display adapter. [D3DADAPTER_DEFAULT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dadapter-default) is always the primary display adapter.

### `DeviceType` [in]

Type: **[D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype)**

Member of the [D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype) enumerated type that denotes the desired device type. If the desired device type is not available, the method will fail.

### `hFocusWindow` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The focus window alerts Direct3D when an application switches from foreground mode to background mode. See Remarks.

* For full-screen mode, the window specified must be a top-level window.
* For windowed mode, this parameter may be **NULL** only if the hDeviceWindow member of *pPresentationParameters* is set to a valid, non-**NULL** value.

### `BehaviorFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of one or more options that control device creation. For more information, see [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate).

### `pPresentationParameters` [in, out]

Type: **[D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters)***

Pointer to a [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters) structure, describing the presentation parameters for the device to be created. If BehaviorFlags specifies [D3DCREATE_ADAPTERGROUP_DEVICE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate), pPresentationParameters is an array. Regardless of the number of heads that exist, only one depth/stencil surface is automatically created.

For Windows 2000 and Windows XP, the full-screen device display refresh rate is set in the following order:

1. User-specified nonzero ForcedRefreshRate registry key, if supported by the device.
2. Application-specified nonzero refresh rate value in the presentation parameter.
3. Refresh rate of the latest desktop, if supported by the device.
4. 75 hertz if supported by the device.
5. 60 hertz if supported by the device.
6. Device default.

An unsupported refresh rate will default to the closest supported refresh rate below it. For example, if the application specifies 63 hertz, 60 hertz will be used. There are no supported refresh rates below 57 hertz.

pPresentationParameters is both an input and an output parameter. Calling this method may change several members including:

* If BackBufferCount, BackBufferWidth, and BackBufferHeight are 0 before the method is called, they will be changed when the method returns.
* If BackBufferFormat equals [D3DFMT_UNKNOWN](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) before the method is called, it will be changed when the method returns.

### `ppReturnedDeviceInterface` [out, retval]

Type: **[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)****

Address of a pointer to the returned [IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, which represents the created device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_DEVICELOST, D3DERR_INVALIDCALL, D3DERR_NOTAVAILABLE, D3DERR_OUTOFVIDEOMEMORY.

## Remarks

This method returns a fully working device interface, set to the required display mode (or windowed), and allocated with the appropriate back buffers. To begin rendering, the application needs only to create and set a depth buffer (assuming EnableAutoDepthStencil is **FALSE** in [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters)).

When you create a Direct3D device, you supply two different window parameters: a focus window (hFocusWindow) and a device window (the hDeviceWindow in [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters)). The purpose of each window is:

* The focus window alerts Direct3D when an application switches from foreground mode to background mode (via Alt-Tab, a mouse click, or some other method). A single focus window is shared by each device created by an application.
* The device window determines the location and size of the back buffer on screen. This is used by Direct3D when the back buffer contents are copied to the front buffer during [Present](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-present).

This method should not be run during the handling of WM_CREATE. An application should never pass a window handle to Direct3D while handling WM_CREATE.
Any call to create, release, or reset the device must be done using the same thread as the window procedure of the focus window.

Note that D3DCREATE_HARDWARE_VERTEXPROCESSING, D3DCREATE_MIXED_VERTEXPROCESSING, and D3DCREATE_SOFTWARE_VERTEXPROCESSING are mutually exclusive flags, and at least one of these vertex processing flags must be specified when calling this method.

Back buffers created as part of the device are only lockable if D3DPRESENTFLAG_LOCKABLE_BACKBUFFER is specified in the presentation parameters. (Multisampled back buffers and depth surfaces are never lockable.)

The methods [Reset](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-reset), [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown), and [TestCooperativeLevel](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-testcooperativelevel) must be called from the same thread that used this method to create a device.

D3DFMT_UNKNOWN can be specified for the windowed mode back buffer format when calling **CreateDevice**, [Reset](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-reset), and [CreateAdditionalSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createadditionalswapchain). This means the application does not have to query the current desktop format before calling **CreateDevice** for windowed mode. For full-screen mode, the back buffer format must be specified.

If you attempt to create a device on a 0x0 sized window, **CreateDevice** will fail.

## See also

[D3DDEVICE_CREATION_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevice-creation-parameters)

[Direct3DCreate9](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-direct3dcreate9)

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)

[Multihead (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/multihead)

[Reset](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-reset)