# IDXGISwapChain2::SetSourceSize

## Description

Sets the source region to be used for the swap chain.

Use **SetSourceSize** to specify the portion of the swap chain from which the operating system presents. This allows an effective resize without calling the more-expensive [IDXGISwapChain::ResizeBuffers](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-resizebuffers) method. Prior to Windows 8.1, calling **IDXGISwapChain::ResizeBuffers** was the only way to resize the swap chain. The source rectangle is always defined by the region [0, 0, Width, Height].

## Parameters

### `Width`

Source width to use for the swap chain. This value must be greater than zero, and must be less than or equal to the overall width of the swap chain.

### `Height`

Source height to use for the swap chain. This value must be greater than zero, and must be less than or equal to the overall height of the swap chain.

## Return value

This method can return:

* E_INVALIDARG if one or more parameters exceed the size of the back buffer.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[GetSourceSize](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-getsourcesize)

[IDXGISwapChain2](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgiswapchain2)