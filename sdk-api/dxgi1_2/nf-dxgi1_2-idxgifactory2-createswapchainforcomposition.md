## Description

Creates a swap chain that you can use to send Direct3D content into the [DirectComposition](https://learn.microsoft.com/windows/win32/directcomp/directcomposition-portal) API, to the [Windows.UI.Xaml](https://learn.microsoft.com/dotnet/api/windows.ui.xaml) framework, or to [Windows UI Library (WinUI)](https://docs.microsoft.com/windows/apps/winui/) XAML, to compose in a window.

## Parameters

### `pDevice` [in]

For Direct3D 11, and earlier versions of Direct3D, this is a pointer to the Direct3D device for the swap chain. For Direct3D 12 this is a pointer to a direct command queue (refer to [ID3D12CommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue)). This parameter cannot be **NULL**. Software drivers, like [D3D_DRIVER_TYPE_REFERENCE](https://learn.microsoft.com/windows/win32/api/d3dcommon/ne-d3dcommon-d3d_driver_type), are not supported for composition swap chains.

### `pDesc` [in]

A pointer to a [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) structure for the swap-chain description. This parameter cannot be **NULL**.

You must specify the [DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/win32/api/dxgi/ne-dxgi-dxgi_swap_effect) value in the **SwapEffect** member of [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) because **CreateSwapChainForComposition** supports only [flip presentation model](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-flip-model).

You must also specify the [DXGI_SCALING_STRETCH](https://learn.microsoft.com/windows/win32/api/dxgi1_2/ne-dxgi1_2-dxgi_scaling) value in the **Scaling** member of [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1).

### `pRestrictToOutput` [in, optional]

A pointer to the [IDXGIOutput](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgioutput) interface for the output to restrict content to. You must also pass the [DXGI_PRESENT_RESTRICT_TO_OUTPUT](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-present) flag in a [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) call to force the content to appear blacked out on any other output. If you want to restrict the content to a different output, you must create a new swap chain. However, you can conditionally restrict content based on the **DXGI_PRESENT_RESTRICT_TO_OUTPUT** flag.

Set this parameter to **NULL** if you don't want to restrict content to an output target.

### `ppSwapChain` [out]

A pointer to a variable that receives a pointer to the [IDXGISwapChain1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1) interface for the swap chain that **CreateSwapChainForComposition** creates.

## Return value

**CreateSwapChainForComposition** returns:

* S_OK if it successfully created a swap chain.
* E_OUTOFMEMORY if memory is unavailable to complete the operation.
* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-error) if the calling application provided invalid data, for example, if *pDesc* or *ppSwapChain* is **NULL**.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-error) topic that are defined by the type of device that you pass to *pDevice*.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **CreateSwapChainForComposition** fails with E_NOTIMPL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/win32/direct3darticles/platform-update-for-windows-7).

## Remarks

You can use composition swap chains with either:

* [DirectComposition](https://learn.microsoft.com/windows/win32/directcomp/directcomposition-portal)'s [IDCompositionVisual](https://learn.microsoft.com/windows/win32/api/dcomp/nn-dcomp-idcompositionvisual) interface,
* System XAML's [SwapChainPanel](https://learn.microsoft.com/uwp/api/windows.ui.xaml.controls.swapchainpanel) or [SwapChainBackgroundPanel](https://learn.microsoft.com/uwp/api/windows.ui.xaml.controls.swapchainbackgroundpanel) classes.
* [Windows UI Library (WinUI) 3](https://docs.microsoft.com/windows/apps/winui/) XAML's [SwapChainPanel](https://learn.microsoft.com/windows/windows-app-sdk/api/winrt/microsoft.ui.xaml.controls.swapchainpanel) or [SwapChainBackgroundPanel](https://learn.microsoft.com/windows/windows-app-sdk/api/winrt/microsoft.ui.xaml.controls.swapchainbackgroundpanel) classes.

For DirectComposition, you can call the [IDCompositionVisual::SetContent](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionvisual-setcontent) method to set the swap chain as the content of a [visual object](https://learn.microsoft.com/windows/win32/directcomp/basic-concepts), which then allows you to bind the swap chain to the visual tree. For XAML, the **SwapChainBackgroundPanel** class exposes a classic COM interface **ISwapChainBackgroundPanelNative**. You can use the [ISwapChainBackgroundPanelNative::SetSwapChain](https://learn.microsoft.com/windows/win32/api/windows.ui.xaml.media.dxinterop/nf-windows-ui-xaml-media-dxinterop-iswapchainbackgroundpanelnative-setswapchain) method to bind to the XAML UI graph. For info about how to use composition swap chains with XAML’s **SwapChainBackgroundPanel** class, see [DirectX and XAML interop](https://learn.microsoft.com/windows/uwp/gaming/directx-and-xaml-interop).

The [IDXGISwapChain::SetFullscreenState](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-setfullscreenstate), [IDXGISwapChain::ResizeTarget](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-resizetarget), [IDXGISwapChain::GetContainingOutput](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-getcontainingoutput), [IDXGISwapChain1::GetHwnd](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-gethwnd), and [IDXGISwapChain::GetCoreWindow](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-getcorewindow) methods aren't valid on this type of swap chain. If you call any of these methods on this type of swap chain, they fail.

For info about how to choose a format for the swap chain's back buffer, see [Converting data for the color space](https://learn.microsoft.com/windows/win32/direct3ddxgi/converting-data-color-space).

## Examples

For a code example showing how to use **CreateSwapChainForComposition**, see [SwapChainPanel and gaming](https://learn.microsoft.com/windows/uwp/gaming/directx-and-xaml-interop#swapchainpanel-and-gaming).

* For WinRT XAML, the [ISwapChainPanelNative](https://learn.microsoft.com/windows/win32/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-iswapchainpanelnative) and [ISwapChainBackgroundPanelNative](https://learn.microsoft.com/windows/win32/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-iswapchainbackgroundpanelnative) interfaces are declared in the `windows.ui.xaml.media.dxinterop.h` header.
* For [Windows UI Library (WinUI)](https://docs.microsoft.com/windows/apps/winui/) XAML, the **ISwapChainPanelNative** and **ISwapChainBackgroundPanelNative** interfaces are declared in the `microsoft.ui.xaml.media.dxinterop.h` header.

## See also

* [For best performance, use DXGI flip model](https://learn.microsoft.com/windows/win32/direct3ddxgi/for-best-performance--use-dxgi-flip-model)
* [IDXGIFactory2](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nn-dxgi1_2-idxgifactory2)