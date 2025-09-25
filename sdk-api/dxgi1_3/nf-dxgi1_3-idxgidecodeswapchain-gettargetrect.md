# IDXGIDecodeSwapChain::GetTargetRect

## Description

Gets the rectangle that defines the target region for the video processing blit operation.

## Parameters

### `pRect` [out]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure
that receives the target region for the swap chain.

## Return value

This method returns S_OK on success, or it returns one of the error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[IDXGIDecodeSwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgidecodeswapchain)