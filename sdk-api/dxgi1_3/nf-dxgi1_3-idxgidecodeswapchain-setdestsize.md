# IDXGIDecodeSwapChain::SetDestSize

## Description

Sets the size of the destination surface to use for the video processing blit operation.

The destination rectangle is the portion of the output surface that receives the blit for this stream. The destination rectangle is given in pixel coordinates, relative to the output surface.

## Parameters

### `Width`

The width of the destination size, in pixels.

### `Height`

The height of the destination size, in pixels.

## Return value

This method returns S_OK on success, or it returns one of the error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[IDXGIDecodeSwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgidecodeswapchain)