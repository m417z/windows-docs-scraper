# IDXGISwapChain2::GetSourceSize

## Description

Gets the source region used for the swap chain.

Use **GetSourceSize** to get the portion of the swap chain from which the operating system presents. The source rectangle is always defined by the region [0, 0, Width, Height]. Use [SetSourceSize](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-setsourcesize) to set this portion of the swap chain.

## Parameters

### `pWidth` [out]

 The current width of the source region of the swap chain. This value can range from 1 to the overall width of the swap chain.

### `pHeight` [out]

The current height of the source region of the swap chain. This value can range from 1 to the overall height of the swap chain.

## Return value

 This method can return error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[IDXGISwapChain2](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgiswapchain2)

[SetSourceSize](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-setsourcesize)