# ID3D10Debug::GetSwapChain

## Description

Get the swap chain that the runtime will use for automatically calling [Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present).

## Parameters

### `ppSwapChain` [out]

Type: **[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)****

Swap chain that the runtime will use for automatically calling [Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

The swap chain retrieved by this method will only be used if D3D10_DEBUG_FEATURE_PRESENT_PER_RENDER_OP is set in the [feature mask](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10debug-setfeaturemask).

## See also

[ID3D10Debug Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10debug)