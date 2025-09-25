# IDirect3DDevice9Ex::WaitForVBlank

## Description

Suspend execution of the calling thread until the next vertical blank signal.

## Parameters

### `iSwapChain` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Swap chain index. This is an optional, zero-based index used to specify a swap chain on a multihead card.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method will always return D3D_OK.

## Remarks

This method allows applications to efficiently throttle their frame rate to that of the monitor associated with the device. Following a vertical blank, the amount of time it takes for the thread to wake up is typically very short.

In some scenarios the hardware may stop generating vertical blank signals when nothing is being displayed on the monitor. In this case, the method will wait approximately 100ms and return with D3D_OK.

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)