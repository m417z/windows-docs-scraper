# IDXGISwapChain::GetLastPresentCount

## Description

Gets the number of times that [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present) or [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) has been called.

## Parameters

### `pLastPresentCount` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a variable that receives the number of calls.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) values.

## Remarks

For info about presentation statistics for a frame, see [DXGI_FRAME_STATISTICS](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_frame_statistics).

## See also

[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)