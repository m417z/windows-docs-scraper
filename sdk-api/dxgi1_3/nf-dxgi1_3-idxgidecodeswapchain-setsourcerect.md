# IDXGIDecodeSwapChain::SetSourceRect

## Description

Sets the rectangle that defines the source region for the video processing blit operation.

The source rectangle is the portion of the input surface that is blitted to the destination surface. The source rectangle is given in pixel coordinates, relative to the input surface.

## Parameters

### `pRect`

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure
that contains the source region to set for the swap chain.

## Return value

This method returns S_OK on success, or it returns one of the error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[IDXGIDecodeSwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgidecodeswapchain)