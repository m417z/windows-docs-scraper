## Description

Checks whether the swap chain currently supports the specified color space, based on the current adapter output (for example, what monitor the swap chain window is being displayed on).

> [!NOTE]
> The swap chain might still be able to set and display color spaces that are not returned as supported. For example the **DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020** and **DXGI_COLOR_SPACE_RGB_FULL_G10_NONE_P709** color spaces will be displayed even if **DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709** is in use, although out-of-gamut colors will be clipped.

While a color space has been successfully set to the swap chain (whether or not it was returned as supported before), it will be returned as supported when queried with this function.

## Parameters

### `ColorSpace` [in]

Type: **[DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type)**

A [DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type)-typed value that specifies color space type to check support for.

### `pColorSpaceSupport` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a variable that receives a combination of [DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/ne-dxgi1_4-dxgi_swap_chain_color_space_support_flag)-typed values that are combined by using a bitwise OR operation. The resulting value specifies options for color space support.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **S_OK** on success, or it returns one of the error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[IDXGISwapChain3](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nn-dxgi1_4-idxgiswapchain3)