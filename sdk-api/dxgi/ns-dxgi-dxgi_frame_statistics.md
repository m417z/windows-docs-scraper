# DXGI_FRAME_STATISTICS structure

## Description

Describes timing and presentation statistics for a frame.

## Members

### `PresentCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that represents the running total count of times that an image was presented to the monitor since the computer booted.

**Note** The number of times that an image was presented to the monitor is not necessarily the same as the number of times
that you called [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present) or [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1).

### `PresentRefreshCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that represents the running total count of v-blanks at which the last image was presented to the monitor and that have happened since the computer booted (for windowed mode, since the swap chain was created).

### `SyncRefreshCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that represents the running total count of v-blanks when the scheduler last sampled the machine time by calling [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter) and that have happened since the computer booted (for windowed mode, since the swap chain was created).

### `SyncQPCTime`

Type: **[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)**

A value that represents the high-resolution performance counter timer.
This value is the same as the value returned by the [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter)
function.

### `SyncGPUTime`

Type: **[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)**

Reserved. Always returns 0.

## Remarks

You initialize the **DXGI_FRAME_STATISTICS** structure with the [IDXGIOutput::GetFrameStatistics](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-getframestatistics) or [IDXGISwapChain::GetFrameStatistics](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-getframestatistics) method.

You can only use [IDXGISwapChain::GetFrameStatistics](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-getframestatistics) for swap chains that either use the flip presentation model or draw in full-screen mode. You set the [DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect) value in the **SwapEffect** member of the [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) structure to specify that the swap chain uses the flip presentation model.

The values in the **PresentCount** and **PresentRefreshCount** members indicate information about when a frame was presented on the display screen. You can use these values to determine whether a glitch occurred. The values in the **SyncRefreshCount** and **SyncQPCTime** members indicate timing information that you can use for audio and video synchronization or very precise animation. If the swap chain draws in full-screen mode, these values are based on when the computer booted.
If the swap chain draws in windowed mode, these values are based on when the swap chain is created.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)