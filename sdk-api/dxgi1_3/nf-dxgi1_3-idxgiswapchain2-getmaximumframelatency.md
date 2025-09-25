# IDXGISwapChain2::GetMaximumFrameLatency

## Description

Gets the number of frames that the swap chain is allowed to queue for rendering.

## Parameters

### `pMaxLatency` [out]

The maximum number of back buffer frames that will be queued for the swap chain. This value is 1 by default, but should be set to 2 if the scene takes longer than it takes for one vertical refresh (typically about 16ms) to draw.

## Return value

Returns S_OK if successful; otherwise, returns one of the following members of the [D3DERR](https://learn.microsoft.com/windows/desktop/direct3d9/d3derr) enumerated type:

* **D3DERR_DEVICELOST**
* **D3DERR_DEVICEREMOVED**
* **D3DERR_DRIVERINTERNALERROR**
* **D3DERR_INVALIDCALL**
* **D3DERR_OUTOFVIDEOMEMORY**

## See also

[DirectX latency sample](https://github.com/microsoftarchive/msdn-code-gallery-microsoft/tree/master/Official%20Windows%20Platform%20Sample/DirectX%20latency%20sample)

[IDXGISwapChain2](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgiswapchain2)

[SetMaximumFrameLatency](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-setmaximumframelatency)