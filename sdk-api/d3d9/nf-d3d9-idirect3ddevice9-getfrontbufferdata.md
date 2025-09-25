# IDirect3DDevice9::GetFrontBufferData

## Description

Generates a copy of the device's front buffer and places that copy in a system memory buffer provided by the application.

## Parameters

### `iSwapChain` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An unsigned integer specifying the swap chain.

### `pDestSurface` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

Pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface that will receive a copy of the contents of the front buffer. The data is returned in successive rows with no intervening space, starting from the vertically highest row on the device's output to the lowest.

For windowed mode, the size of the destination surface should be the size of the desktop. For full-screen mode, the size of the destination surface should be the screen size.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_DRIVERINTERNALERROR, D3DERR_DEVICELOST, D3DERR_INVALIDCALL

## Remarks

The buffer pointed to by pDestSurface will be filled with a representation of the front buffer, converted to the standard 32 bits per pixel format D3DFMT_A8R8G8B8.

This method is the only way to capture an antialiased screen shot.

This function is very slow, by design, and should not be used in any performance-critical path.

For more information, see [Lost Devices and Retrieved Data](https://learn.microsoft.com/windows/desktop/direct3d9/lost-devices).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)