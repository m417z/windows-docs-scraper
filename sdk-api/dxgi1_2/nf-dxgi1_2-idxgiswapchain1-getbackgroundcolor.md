# IDXGISwapChain1::GetBackgroundColor

## Description

Retrieves the background color of the swap chain.

## Parameters

### `pColor` [out]

A pointer to a [DXGI_RGBA](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-rgba) structure that receives the background color of the swap chain.

## Return value

**GetBackgroundColor** returns:

* S_OK if it successfully retrieves the background color.
* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if the *pColor* parameter is invalid, for example, *pColor* is NULL.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

**Note** The background color that **GetBackgroundColor** retrieves does not indicate what the screen currently displays. The background color indicates what the screen will display with your next call to the [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) method. The default value of the background color is black with full opacity: 0,0,0,1.

## See also

[IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1)

[IDXGISwapChain1::SetBackgroundColor](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-setbackgroundcolor)