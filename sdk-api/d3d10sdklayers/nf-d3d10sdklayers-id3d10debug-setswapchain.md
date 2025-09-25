# ID3D10Debug::SetSwapChain

## Description

Set a swap chain that the runtime will use for automatically calling [Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present).

## Parameters

### `pSwapChain` [in]

Type: **[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)***

Swap chain that the runtime will use for automatically calling [Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present); must have been created with the [DXGI_SWAP_EFFECT_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-createswapchain) swap-effect flag.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

**Note** If you call this API in a Session 0 process, it returns [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

The swap chain set by this method will only be used if D3D10_DEBUG_FEATURE_PRESENT_PER_RENDER_OP is set in the [feature mask](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10debug-setfeaturemask).

## See also

[ID3D10Debug Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10debug)