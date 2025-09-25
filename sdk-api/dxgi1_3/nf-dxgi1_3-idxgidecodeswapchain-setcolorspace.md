# IDXGIDecodeSwapChain::SetColorSpace

## Description

Sets the color space used by the swap chain.

## Parameters

### `ColorSpace`

A pointer to a combination of [DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/ne-dxgi1_3-dxgi_multiplane_overlay_ycbcr_flags)-typed values that are combined by using a bitwise OR operation. The resulting value specifies the color space to set for the swap chain.

## Return value

This method returns S_OK on success, or it returns one of the error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[IDXGIDecodeSwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgidecodeswapchain)