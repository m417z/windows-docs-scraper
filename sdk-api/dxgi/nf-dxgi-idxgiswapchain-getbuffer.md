# IDXGISwapChain::GetBuffer

## Description

Accesses one of the swap-chain's back buffers.

## Parameters

### `Buffer`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based buffer index.

If the swap chain's swap effect is [DXGI_SWAP_EFFECT_DISCARD](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect), this method can only access the first buffer; for this situation, set the index to zero.

If the swap chain's swap effect is either [DXGI_SWAP_EFFECT_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect), only the swap chain's zero-index buffer can be read from and written to. The swap chain's buffers with indexes greater than zero can only be read from; so if you call the [IDXGIResource::GetUsage](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiresource-getusage) method for such buffers, they have the [DXGI_USAGE_READ_ONLY](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-usage) flag set.

If the swap chain's swap effect is [DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect), the relationship between indices and buffers is consistent. The result is identical if you get the swap chain's zero-index buffer after each time [IDXGISwapChain::Present](https://learn.microsoft.com/windows/win32/api/dxgi/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-present) is called. A correct frame index should be used to retrieve the current backbuffer.

### `riid` [in]

Type: **REFIID**

The type of interface used to manipulate the buffer.

### `ppSurface` [out]

Type: **void****

A pointer to a back-buffer interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## See also

[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)