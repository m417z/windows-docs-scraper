# IDirect3DDevice9Ex::GetDisplayModeEx

## Description

Retrieves the display mode's spatial resolution, color resolution, refresh frequency, and rotation settings.

## Parameters

### `iSwapChain` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An unsigned integer specifying the swap chain.

### `pMode` [out]

Type: **[D3DDISPLAYMODEEX](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodeex)***

Pointer to a [D3DDISPLAYMODEEX](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodeex) structure containing data about the display mode of the adapter. As opposed to the display mode of the device, which may not be active if the device does not own full-screen mode. Can be set to **NULL**.

### `pRotation` [out]

Type: **[D3DDISPLAYROTATION](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplayrotation)***

Pointer to a [D3DDISPLAYROTATION](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplayrotation) indicating the type of screen rotation the application will do. The value returned through this pointer is important when the [D3DPRESENTFLAG_NOAUTOROTATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresentflag) flag is used; otherwise, it can be set to **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)