# IDirect3D9Ex::CreateDeviceEx

## Description

Creates a device to represent the display adapter.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number that denotes the display adapter. [D3DADAPTER_DEFAULT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dadapter-default) is always the primary display adapter.

### `DeviceType` [in]

Type: **[D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype)**

Specifies the type of device. See [D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype). If the desired device type is not available, the method will fail.

### `hFocusWindow` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The focus window alerts Direct3D when an application switches from foreground mode to background mode. For full-screen mode, the window specified must be a top-level window. For windowed mode, this parameter may be **NULL** only if the hDeviceWindow member of pPresentationParameters is set to a valid, non-**NULL** value.

### `BehaviorFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of one or more options (see [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate)) that control device creation.

### `pPresentationParameters` [in, out]

Type: **[D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters)***

Pointer to a [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters) structure, describing the presentation parameters for the device to be created. If *BehaviorFlags* specifies [D3DCREATE_ADAPTERGROUP_DEVICE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate), this parameter is an array. Regardless of the number of heads that exist, only one depth/stencil surface is automatically created.

This parameter is both an input and an output parameter. Calling this method may change several members including:

* If BackBufferCount, BackBufferWidth, and BackBufferHeight are 0 before the method is called, they will be changed when the method returns.
* If BackBufferFormat equals [D3DFMT_UNKNOWN](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) before the method is called, it will be changed when the method returns.

### `pFullscreenDisplayMode` [in, out]

Type: **[D3DDISPLAYMODEEX](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodeex)***

The display mode for when the device is set to fullscreen. See [D3DDISPLAYMODEEX](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodeex). If *BehaviorFlags* specifies [D3DCREATE_ADAPTERGROUP_DEVICE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate), this parameter is an array. This parameter must be **NULL** for windowed mode.

### `ppReturnedDeviceInterface` [out, retval]

Type: **[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)****

Address of a pointer to the returned [IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex), which represents the created device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns S_OK when rendering device along with swapchain buffers are created successfully. D3DERR_DEVICELOST is returned when any error other than invalid caller input is encountered.

## See also

[IDirect3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex)