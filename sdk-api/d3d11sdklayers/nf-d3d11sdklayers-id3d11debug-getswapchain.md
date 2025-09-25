# ID3D11Debug::GetSwapChain

## Description

Get the swap chain that the runtime will use for automatically calling [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present).

## Parameters

### `ppSwapChain` [out]

Type: **[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)****

Swap chain that the runtime will use for automatically calling [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The swap chain retrieved by this method will only be used if D3D11_DEBUG_FEATURE_PRESENT_PER_RENDER_OP is set in the [feature mask](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11debug-setfeaturemask).

## See also

[ID3D11Debug Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11debug)