# IDXGISwapChain1::GetHwnd

## Description

Retrieves the underlying [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) for this swap-chain object.

## Parameters

### `pHwnd` [out]

A pointer to a variable that receives the [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) for the swap-chain object.

## Return value

Returns S_OK if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

If *pHwnd* receives **NULL** (that is, the swap chain is not [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)-based), **GetHwnd** returns [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

Applications call the [IDXGIFactory2::CreateSwapChainForHwnd](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd) method to create a swap chain that is associated with an [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types).

## See also

[IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1)