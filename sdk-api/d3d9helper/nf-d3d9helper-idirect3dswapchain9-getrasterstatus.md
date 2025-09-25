# IDirect3DSwapChain9::GetRasterStatus

## Description

Returns information describing the raster of the monitor on which the swap chain is presented.

## Parameters

### `pRasterStatus` [out]

Type: **[D3DRASTER_STATUS](https://learn.microsoft.com/windows/desktop/direct3d9/d3draster-status)***

Pointer to a [D3DRASTER_STATUS](https://learn.microsoft.com/windows/desktop/direct3d9/d3draster-status) structure filled with information about the position or other status of the raster on the monitor driven by this adapter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if pRasterStatus is invalid or if the device does not support reading the current scan line. To determine if the device supports reading the scan line, check for the D3DCAPS_READ_SCANLINE flag in the Caps member of [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9).

## See also

[D3DRASTER_STATUS](https://learn.microsoft.com/windows/desktop/direct3d9/d3draster-status)

[IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9)