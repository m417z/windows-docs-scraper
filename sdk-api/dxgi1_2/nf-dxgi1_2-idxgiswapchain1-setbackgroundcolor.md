# IDXGISwapChain1::SetBackgroundColor

## Description

Changes the background color of the swap chain.

## Parameters

### `pColor` [in]

A pointer to a [DXGI_RGBA](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-rgba) structure that specifies the background color to set.

## Return value

**SetBackgroundColor** returns:

* S_OK if it successfully set the background color.
* E_INVALIDARG if the *pColor* parameter is incorrect, for example, *pColor* is NULL or any of the floating-point values of the members of [DXGI_RGBA](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-rgba) to which *pColor* points are outside the range from 0.0 through 1.0.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **SetBackgroundColor** fails with E_NOTIMPL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

The background color affects only swap chains that you create with [DXGI_SCALING_NONE](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_scaling) in windowed mode. You pass this value in a call to [IDXGIFactory2::CreateSwapChainForHwnd](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd), [IDXGIFactory2::CreateSwapChainForCoreWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcorewindow), or [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition). Typically, the background color is not visible unless the swap-chain contents are smaller than the destination window.

When you set the background color, it is not immediately realized. It takes effect in conjunction with your next call to the [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) method. The [DXGI_PRESENT](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present) flags that you pass to **IDXGISwapChain1::Present1** can help achieve the effect that you require. For example, if you call **SetBackgroundColor** and then call **IDXGISwapChain1::Present1** with the *Flags* parameter set to [DXGI_PRESENT_DO_NOT_SEQUENCE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present), you change only the background color without changing the displayed contents of the swap chain.

When you call the [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) method to display contents of the swap chain, **IDXGISwapChain1::Present1** uses the [DXGI_ALPHA_MODE](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_alpha_mode) value that is specified in the **AlphaMode** member of the [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) structure to determine how to handle the **a** member of the [DXGI_RGBA](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-rgba) structure, the alpha value of the background color, that achieves window transparency. For example, if **AlphaMode** is **DXGI_ALPHA_MODE_IGNORE**, **IDXGISwapChain1::Present1** ignores the a member of **DXGI_RGBA**.

**Note** Like all presentation data, we recommend that you perform floating point operations in a linear color space. When the desktop is in a fixed bit color depth mode, the operating system converts linear color data to standard RGB data (sRGB, gamma 2.2 corrected space) to compose to the screen. For more info, see [Converting data for the color space](https://learn.microsoft.com/windows/desktop/direct3ddxgi/converting-data-color-space).

## See also

[DXGI_SCALING](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_scaling)

[IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1)

[IDXGISwapChain1::GetBackgroundColor](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-getbackgroundcolor)