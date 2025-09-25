# DXGI_FRAME_STATISTICS_MEDIA structure

## Description

Used to verify system approval for the app's custom present duration (custom refresh rate). Approval should be continuously verified on a frame-by-frame basis.

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

### `CompositionMode`

Type: **[DXGI_FRAME_PRESENTATION_MODE](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/ne-dxgi1_3-dxgi_frame_presentation_mode)**

A value indicating the composition presentation mode. This value is used to determine whether the app should continue to use the decode swap chain. See [DXGI_FRAME_PRESENTATION_MODE](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/ne-dxgi1_3-dxgi_frame_presentation_mode).

### `ApprovedPresentDuration`

Type: **UINT**

If the system approves an app's custom present duration request, this field is set to the approved custom present duration.

If the app's custom present duration request is not approved, this field is set to zero.

## Remarks

This structure is used with the [GetFrameStatisticsMedia](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchainmedia-getframestatisticsmedia) method.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)

[IDXGISwapChainMedia](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgiswapchainmedia)