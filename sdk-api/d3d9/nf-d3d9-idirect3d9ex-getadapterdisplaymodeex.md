# IDirect3D9Ex::GetAdapterDisplayModeEx

## Description

Retrieves the current display mode and rotation settings of the adapter.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number that denotes the display adapter to query. D3DADAPTER_DEFAULT is always the primary display adapter.

### `pMode` [in, out]

Type: **[D3DDISPLAYMODEEX](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodeex)***

Pointer to a [D3DDISPLAYMODEEX](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodeex) structure containing data about the display mode of the adapter. As opposed to the display mode of the device, which may not be active if the device does not own full-screen mode. Can be set to **NULL**.

### `pRotation` [in, out]

Type: **[D3DDISPLAYROTATION](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplayrotation)***

Pointer to a [D3DDISPLAYROTATION](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplayrotation) structure indicating the type of screen rotation the application will do. The value returned through this pointer is important when the [D3DPRESENTFLAG_NOAUTOROTATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresentflag) flag is used; otherwise, it can be set to **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.

If *Adapter* is out of range or *pMode* is invalid, this method returns D3DERR_INVALIDCALL.

## Remarks

**GetAdapterDisplayModeEx** does not return the correct format when the display is in an extended format, such as 2:10:10:10. Instead, it returns the format X8R8G8B8.

To windowed applications, a value of S_PRESENT_MODE_CHANGED returned from [PresentEx](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-presentex) or [CheckDeviceState](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-checkdevicestate) indicates that the display mode changed and that the current display mode might have a different format. To avoid a color-converting Present blt, windowed applications can optionally get new display mode information by using this method and adjusting its swap chain format accordingly. This method returns D3DERR_NOTAVAILABLE if this head is no longer part of the desktop or if the monitor is disconnected.

## See also

[IDirect3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex)