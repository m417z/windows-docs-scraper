# IDXGISwapChain2::GetFrameLatencyWaitableObject

## Description

Returns a waitable handle that signals when the DXGI adapter has finished presenting a new frame.

Windows 8.1 introduces new APIs that allow lower-latency rendering by waiting until the previous frame is presented to the display before drawing the next frame. To use this method, first create the DXGI swap chain with the [DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_chain_flag) flag set, then call **GetFrameLatencyWaitableObject** to retrieve the waitable handle. Use the waitable handle with [WaitForSingleObjectEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobjectex) to synchronize rendering of each new frame with the end of the previous frame. For every frame it renders, the app should wait on this handle before starting any rendering operations. Note that this requirement includes the first frame the app renders with the swap chain. See the [DirectXLatency sample](https://github.com/microsoftarchive/msdn-code-gallery-microsoft/tree/master/Official%20Windows%20Platform%20Sample/DirectX%20latency%20sample). When you are done with the handle, use [CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) to close it.

## Return value

A handle to the waitable object, or NULL if the swap chain was not created with [DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_chain_flag).

## Remarks

When an application is finished using the object handle returned by
**IDXGISwapChain2::GetFrameLatencyWaitableObject**, use the [CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) function to close the handle.

## See also

[DirectX latency sample](https://github.com/microsoftarchive/msdn-code-gallery-microsoft/tree/master/Official%20Windows%20Platform%20Sample/DirectX%20latency%20sample)

[GetMaximumFrameLatency](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-getmaximumframelatency)

[IDXGISwapChain2](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgiswapchain2)

[SetMaximumFrameLatency](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-setmaximumframelatency)