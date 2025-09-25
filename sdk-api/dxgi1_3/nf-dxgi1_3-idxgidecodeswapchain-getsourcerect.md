# IDXGIDecodeSwapChain::GetSourceRect

## Description

Gets the source region that is used for the swap chain.

## Parameters

### `pRect` [out]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure
that receives the source region for the swap chain.

## Return value

This method returns S_OK on success, or it returns one of the error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[IDXGIDecodeSwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgidecodeswapchain)