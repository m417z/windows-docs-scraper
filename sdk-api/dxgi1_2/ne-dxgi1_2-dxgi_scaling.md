## Description

Identifies resize behavior when the back-buffer size does not match the size of the target output.

## Constants

### `DXGI_SCALING_STRETCH:0`

Directs DXGI to make the back-buffer contents scale to fit the presentation target size. This is the implicit behavior of DXGI when you call the [IDXGIFactory::CreateSwapChain](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgifactory-createswapchain) method.

### `DXGI_SCALING_NONE:1`

Directs DXGI to make the back-buffer contents appear without any scaling when the presentation target size is not equal to the back-buffer size. The top edges of the back buffer and presentation target are aligned together. If the WS_EX_LAYOUTRTL style is associated with the [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) handle to the target output window, the right edges of the back buffer and presentation target are aligned together; otherwise, the left edges are aligned together. All target area outside the back buffer is filled with window background color.

This value specifies that all target areas outside the back buffer of a swap chain are filled with the background color that you specify in a call to [IDXGISwapChain1::SetBackgroundColor](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-setbackgroundcolor).

### `DXGI_SCALING_ASPECT_RATIO_STRETCH:2`

Directs DXGI to make the back-buffer contents scale to fit the presentation target size, while preserving the aspect ratio of the back-buffer. If the scaled back-buffer does not fill the presentation area, it will be centered with black borders.

This constant is supported on Windows Phone 8 and Windows 10.

Note that with legacy Win32 window swapchains, this works the same as DXGI_SCALING_STRETCH.

## Remarks

The DXGI_SCALING_NONE value is supported only for flip presentation model swap chains that you create with the [DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/win32/api/dxgi/ne-dxgi-dxgi_swap_effect) or [DXGI_SWAP_EFFECT_FLIP_DISCARD](https://learn.microsoft.com/windows/win32/api/dxgi/ne-dxgi-dxgi_swap_effect) value. You pass these values in a call to [IDXGIFactory2::CreateSwapChainForHwnd](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd), [IDXGIFactory2::CreateSwapChainForCoreWindow](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcorewindow), or [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition).

DXGI_SCALING_ASPECT_RATIO_STRETCH will prefer to use a horizontal fill, otherwise it will use a vertical fill, using the following logic.

``` syntax
float aspectRatio = backBufferWidth / float(backBufferHeight);

 // Horizontal fill
 float scaledWidth = outputWidth;
 float scaledHeight = outputWidth / aspectRatio;
 if (scaledHeight >= outputHeight)
 {
   // Do vertical fill
   scaledWidth = outputHeight * aspectRatio;
   scaledHeight = outputHeight;
 }

 float offsetX = (outputWidth - scaledWidth) * 0.5f;
 float offsetY = (outputHeight - scaledHeight) * 0.5f;

 rect.left = static_cast<LONG>(offsetX);
 rect.top = static_cast<LONG>(offsetY);
 rect.right = static_cast<LONG>(offsetX + scaledWidth);
 rect.bottom = static_cast<LONG>(offsetY + scaledHeight);

 rect.left = std::max<LONG>(0, rect.left);
 rect.top = std::max<LONG>(0, rect.top);
 rect.right = std::min<LONG>(static_cast<LONG>(outputWidth), rect.right);
 rect.bottom = std::min<LONG>(static_cast<LONG>(outputHeight), rect.bottom);

```

Note that *outputWidth* and *outputHeight* are the pixel sizes of the presentation target size. In the case of **CoreWindow**, this requires converting the *logicalWidth* and *logicalHeight* values from DIPS to pixels using the window's DPI property.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)

[DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1)