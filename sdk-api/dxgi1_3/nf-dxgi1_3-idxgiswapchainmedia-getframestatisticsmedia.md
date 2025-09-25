# IDXGISwapChainMedia::GetFrameStatisticsMedia

## Description

Queries the system for a [DXGI_FRAME_STATISTICS_MEDIA](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/ns-dxgi1_3-dxgi_frame_statistics_media) structure that indicates whether a custom refresh rate is currently approved by the system.

## Parameters

### `pStats` [out]

A [DXGI_FRAME_STATISTICS_MEDIA](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/ns-dxgi1_3-dxgi_frame_statistics_media) structure indicating whether the system currently approves the custom refresh rate request.

## Return value

This method returns S_OK on success, or a DXGI error code on failure.

## See also

[IDXGISwapChainMedia](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgiswapchainmedia)