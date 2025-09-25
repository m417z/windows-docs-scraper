## Description

Options for swap-chain behavior.

## Constants

### `DXGI_SWAP_CHAIN_FLAG_NONPREROTATED:1`

Set this flag to turn off automatic image rotation; that is, do not perform a rotation when transferring the contents of the front buffer to the monitor.
Use this flag to avoid a bandwidth penalty when an application expects to handle rotation. This option is valid only during full-screen mode.

### `DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH:2`

Set this flag to enable an application to switch modes by calling [IDXGISwapChain::ResizeTarget](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-resizetarget).
When switching from windowed to full-screen mode, the display mode (or monitor resolution) will be changed to match the dimensions of the application window.

### `DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE:4`

Set this flag to enable an application to render using GDI on a swap chain or a surface.
This will allow the application to call [IDXGISurface1::GetDC](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgisurface1-getdc) on the 0th back buffer or a surface.

This flag is not applicable for Direct3D 12.

### `DXGI_SWAP_CHAIN_FLAG_RESTRICTED_CONTENT:8`

Set this flag to indicate that the swap chain might contain protected content; therefore, the operating system supports the creation of the swap chain only when driver and hardware protection is used. If the driver and hardware do not support content protection, the call to create a resource for the swap chain fails.

**Direct3D 11:** This enumeration value is supported starting with Windows 8.

### `DXGI_SWAP_CHAIN_FLAG_RESTRICT_SHARED_RESOURCE_DRIVER:16`

Set this flag to indicate that shared resources that are created within the swap chain must be protected by using the driver’s mechanism for restricting access to shared surfaces.

**Direct3D 11:** This enumeration value is supported starting with Windows 8.

### `DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY:32`

Set this flag to restrict presented content to the local displays. Therefore, the presented content is not accessible via remote accessing or through the [desktop duplication APIs](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication).

This flag supports the window content protection features of Windows. Applications can use this flag to protect their own onscreen window content from being captured or copied through a specific set of public operating system features and APIs.

If you use this flag with windowed ([HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) or **IWindow**) swap chains where another process created the **HWND**, the owner of the **HWND** must use the [SetWindowDisplayAffinity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowdisplayaffinity) function appropriately in order to allow calls to [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present) or [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) to succeed.

**Direct3D 11:** This enumeration value is supported starting with Windows 8.

### `DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT:64`

Set this flag to create a waitable object you can use to ensure rendering does not begin while a frame is still being presented. When this flag is used, the swapchain's latency must be set with the [IDXGISwapChain2::SetMaximumFrameLatency](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-setmaximumframelatency) API instead of [IDXGIDevice1::SetMaximumFrameLatency](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgidevice1-setmaximumframelatency).

This flag isn't supported in full-screen mode, unless the render API is Direct3D 12.

**Note** This enumeration value is supported starting with Windows 8.1.

### `DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER:128`

Set this flag to create a swap chain in the foreground layer for multi-plane rendering. This flag can only be used with [CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow) swap chains, which are created with [CreateSwapChainForCoreWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcorewindow). Apps should not create foreground swap chains if [IDXGIOutput2::SupportsOverlays](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgioutput2-supportsoverlays) indicates that hardware support for overlays is not available.

Note that [IDXGISwapChain::ResizeBuffers](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-resizebuffers) cannot be used to add or remove this flag.

**Note** This enumeration value is supported starting with Windows 8.1.

### `DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO:256`

Set this flag to create a swap chain for full-screen video.

**Note** This enumeration value is supported starting with Windows 8.1.

### `DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO:512`

Set this flag to create a swap chain for YUV video.

**Note** This enumeration value is supported starting with Windows 8.1.

### `DXGI_SWAP_CHAIN_FLAG_HW_PROTECTED:1024`

Indicates that the swap chain should be created such that all underlying resources can be protected by the hardware. Resource creation will fail if hardware content protection is not supported.

This flag has the following restrictions:

* This flag can only be used with swap effect **DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL**.

**Note** Creating a swap chain using this flag does not automatically guarantee that hardware protection will be enabled for the underlying allocation. Some implementations require that the DRM components are first initialized prior to any guarantees of protection.

**Note** This enumeration value is supported starting with Windows 10.

### `DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING:2048`

Tearing support is a requirement to enable displays that support variable refresh rates to function properly when the application presents a swap chain tied to a full screen borderless window. Win32 apps can already achieve tearing in fullscreen exclusive mode by calling [SetFullscreenState](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-setfullscreenstate)(TRUE), but the recommended approach for Win32 developers is to use this tearing flag instead. This flag requires the use of a **DXGI_SWAP_EFFECT_FLIP_*** swap effect.

To check for hardware support of this feature, refer to [IDXGIFactory5::CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nf-dxgi1_5-idxgifactory5-checkfeaturesupport). For usage information refer to [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present) and the [DXGI_PRESENT](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present) flags.

> [!NOTE]
> [**IDXGISwapChain::ResizeBuffers**](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-resizebuffers) can't be used to add or remove this flag.

### `DXGI_SWAP_CHAIN_FLAG_RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS:4096`

## Remarks

This enumeration is used by the [DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_swap_chain_desc) structure and the [IDXGISwapChain::ResizeTarget](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-resizetarget) method.

This enumeration is also used by the [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) structure.

You don't need to set **DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY** for swap chains that you create in full-screen mode with the [IDXGIFactory::CreateSwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-createswapchain) method because those swap chains already behave as if **DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY** is set. That is, presented content is not accessible by remote access or through the [desktop duplication APIs](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication).

Swap chains that you create with the [IDXGIFactory2::CreateSwapChainForHwnd](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd), [IDXGIFactory2::CreateSwapChainForCoreWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcorewindow), and [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition) methods are not protected if **DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY** is not set and are protected if **DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY** is set. When swap chains are protected, screen scraping is prevented and, in full-screen mode, presented content is not accessible through the [desktop duplication APIs](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication).

When you call [IDXGISwapChain::ResizeBuffers](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-resizebuffers) to change the swap chain's back buffer, you can reset or change all **DXGI_SWAP_CHAIN_FLAG** flags.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)