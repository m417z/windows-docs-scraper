# IDXGISwapChain1::GetFullscreenDesc

## Description

Gets a description of a full-screen swap chain.

## Parameters

### `pDesc` [out]

A pointer to a [DXGI_SWAP_CHAIN_FULLSCREEN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_fullscreen_desc) structure that describes the full-screen swap chain.

## Return value

**GetFullscreenDesc** returns:

* S_OK if it successfully retrieved the description of the full-screen swap chain.
* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) for non-[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) swap chains or if *pDesc* is **NULL**.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

The semantics of **GetFullscreenDesc** are identical to that of the [IDXGISwapchain::GetDesc](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-getdesc) method for [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)-based swap chains.

## See also

[IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1)