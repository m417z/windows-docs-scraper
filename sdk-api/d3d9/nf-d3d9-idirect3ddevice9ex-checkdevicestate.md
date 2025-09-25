# IDirect3DDevice9Ex::CheckDeviceState

## Description

Reports the current cooperative-level status of the Direct3D device for a windowed or full-screen application.

## Parameters

### `hDestinationWindow` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The destination window handle to check for occlusion. When this parameter is **NULL**, S_PRESENT_OCCLUDED is returned when another device has fullscreen ownership. When the window handle is not **NULL**, window's client area is checked for occlusion. A window is occluded if any part of it is obscured by another application.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Possible return values include: D3D_OK, D3DERR_DEVICELOST, D3DERR_DEVICEHUNG, D3DERR_DEVICEREMOVED, or D3DERR_OUTOFVIDEOMEMORY (see [D3DERR](https://learn.microsoft.com/windows/desktop/direct3d9/d3derr)), or S_PRESENT_MODE_CHANGED, or S_PRESENT_OCCLUDED (see [S_PRESENT](https://learn.microsoft.com/windows/desktop/direct3d9/device-state-return-codes)).

## Remarks

This method replaces [IDirect3DDevice9::TestCooperativeLevel](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-testcooperativelevel), which always returns S_OK in Direct3D 9Ex applications.

We recommend not to call **CheckDeviceState** every frame. Instead, call **CheckDeviceState** only if the [IDirect3DDevice9Ex::PresentEx](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-presentex) method returns a failure code.

See [Lost Device Behavior Changes](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh) for more information about lost, hung, and removed devices.

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)