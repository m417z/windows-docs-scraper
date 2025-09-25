# IDXGISwapChain::GetDesc

## Description

[Starting with Direct3D 11.1, we recommend not to use **GetDesc** anymore to get a description of the swap chain. Instead, use [IDXGISwapChain1::GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-getdesc1).]

Get a description of the swap chain.

## Parameters

### `pDesc` [out]

Type: **[DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_swap_chain_desc)***

A pointer to the swap-chain description (see [DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_swap_chain_desc)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## See also

[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)