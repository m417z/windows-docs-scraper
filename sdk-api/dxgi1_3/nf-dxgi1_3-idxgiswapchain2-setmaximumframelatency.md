# IDXGISwapChain2::SetMaximumFrameLatency

## Description

Sets the number of frames that the swap chain is allowed to queue for rendering.

## Parameters

### `MaxLatency`

The maximum number of back buffer frames that will be queued for the swap chain. This value is 1 by default.

## Return value

Returns S_OK if successful; otherwise, DXGI_ERROR_DEVICE_REMOVED if the device was removed.

## Remarks

This method is only valid for use on swap chains created with [DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_chain_flag). Otherwise, the result will be DXGI_ERROR_INVALID_CALL.

## See also

[DirectX latency sample](https://github.com/microsoftarchive/msdn-code-gallery-microsoft/tree/master/Official%20Windows%20Platform%20Sample/DirectX%20latency%20sample)

[GetMaximumFrameLatency](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-getmaximumframelatency)

[IDXGISwapChain2](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgiswapchain2)