# DXGI_SWAP_CHAIN_FULLSCREEN_DESC structure

## Description

Describes full-screen mode for a swap chain.

## Members

### `RefreshRate`

A [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure that describes the refresh rate in hertz. Setting the numerator to 0 forces the native display's refresh rate.

### `ScanlineOrdering`

A member of the [DXGI_MODE_SCANLINE_ORDER](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173067(v=vs.85)) enumerated type that describes the scan-line drawing mode.

### `Scaling`

A member of the [DXGI_MODE_SCALING](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173066(v=vs.85)) enumerated type that describes the scaling mode.

### `Windowed`

A Boolean value that specifies whether the swap chain is in windowed mode. **TRUE** if the swap chain is in windowed mode; otherwise, **FALSE**.

## Remarks

This structure is used by the [CreateSwapChainForHwnd](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd) and [GetFullscreenDesc](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-getfullscreendesc) methods.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)