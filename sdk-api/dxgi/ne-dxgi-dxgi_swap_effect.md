## Description

Options for handling pixels in a display surface after calling [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1).

## Constants

### `DXGI_SWAP_EFFECT_DISCARD:0`

Use this flag to specify the bit-block transfer (bitblt) model and to specify that DXGI discard the contents of the back buffer after you call [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1).
This flag is valid for a swap chain with more than one back buffer, although, applications only have read and write access to buffer 0.
Use this flag to enable the display driver to select the most efficient presentation technique for the swap chain.
**Direct3D 12:** This enumeration value is never supported. D3D12 apps must use **DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL** or **DXGI_SWAP_EFFECT_FLIP_DISCARD**.

**Note** There are differences between full screen exclusive and full screen UWP. If you are porting a Direct3D 11 application to UWP on a Windows PC, be aware that the use of **DXGI_SWAP_EFFECT_DISCARD** when creating swap chains does
not behave the same way in UWP as it does in Win32, and its use may be detrimental to GPU performance.

This is because UWP applications are forced into FLIP swap modes (even if other swap modes are set), because this reduces the computation
time used by the memory copies originally done by the older bitblt model.

The recommended approach is to manually convert DX11 Discard swap chains to use flip models within UWP, using **DXGI_SWAP_EFFECT_FLIP_DISCARD** instead of **DXGI_SWAP_EFFECT_DISCARD** where possible.
Refer to the Example below, and see [this article](https://learn.microsoft.com/windows/win32/direct3ddxgi/for-best-performance--use-dxgi-flip-model) for more information.

### `DXGI_SWAP_EFFECT_SEQUENTIAL:1`

Use this flag to specify the bitblt model and to specify that DXGI persist the contents of the back buffer after you call [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1).
Use this option to present the contents of the swap chain in order, from the first buffer (buffer 0) to the last buffer.
This flag cannot be used with multisampling.
**Direct3D 12:** This enumeration value is never supported. D3D12 apps must use **DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL** or **DXGI_SWAP_EFFECT_FLIP_DISCARD**.

**Note** For best performance, use **DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL** instead of **DXGI_SWAP_EFFECT_SEQUENTIAL**. See [this article](https://learn.microsoft.com/windows/win32/direct3ddxgi/for-best-performance--use-dxgi-flip-model) for more information.

### `DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL:3`

Use this flag to specify the flip presentation model and to specify that DXGI persist the contents of the back buffer after you call [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1). This flag cannot be used with multisampling.

**Direct3D 11:** This enumeration value is supported starting with Windows 8.

### `DXGI_SWAP_EFFECT_FLIP_DISCARD:4`

Use this flag to specify the flip presentation model and to specify that DXGI discard the contents of the back buffer after you call [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1).
This flag cannot be used with multisampling and partial presentation.
See [DXGI 1.4 Improvements](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-1-4-improvements).

**Direct3D 11:** This enumeration value is supported starting with Windows 10.
This flag is valid for a swap chain with more than one back buffer; although applications have read and write access only to buffer 0.

**Note** Windows Store apps must use **DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL** or **DXGI_SWAP_EFFECT_FLIP_DISCARD**.

## Remarks

This enumeration is used by the [DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/win32/api/dxgi/ns-dxgi-dxgi_swap_chain_desc) and [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) structures.
In D3D12, only **DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL** and **DXGI_SWAP_EFFECT_FLIP_DISCARD** are supported, and the bitblt models are not. Because of this, multisampling a back buffer is not supported in D3D12, and you must manually perform multisampling in the app using **[ID3D12GraphicsCommandList::ResolveSubresource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-resolvesubresource)** or **[ID3D12GraphicsCommandList1::ResolveSubresourceRegion](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist1-resolvesubresourceregion)**.

To use multisampling with **DXGI_SWAP_EFFECT_SEQUENTIAL** or **DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL**, you must perform the multisampling in a separate render target. For example, create a multisampled texture by calling [ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-id3d11device-createtexture2d) with a filled [D3D11_TEXTURE2D_DESC](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_texture2d_desc) structure (**BindFlags** member set to [D3D11_BIND_RENDER_TARGET](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_bind_flag) and **SampleDesc** member with multisampling parameters). Next call [ID3D11Device::CreateRenderTargetView](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-id3d11device-createrendertargetview) to create a render-target view for the texture, and render your scene into the texture. Finally call [ID3D11DeviceContext::ResolveSubresource](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-id3d11devicecontext-resolvesubresource) to resolve the multisampled texture into your non-multisampled swap chain.

The primary difference between presentation models is how back-buffer contents get to the Desktop Window Manager (DWM) for composition. In the bitblt model, which is used with the **DXGI_SWAP_EFFECT_DISCARD** and **DXGI_SWAP_EFFECT_SEQUENTIAL** values, contents of the back buffer get copied into the redirection surface on each call to [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1). In the flip model, which is used with the **DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL** value, all back buffers are shared with the DWM. Therefore, the DWM can compose straight from those back buffers without any additional copy operations.
In general, the flip model is the more efficient model. The flip model also provides more features, such as enhanced present statistics.
The difference between **DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL** and **DXGI_SWAP_EFFECT_FLIP_DISCARD** is that **DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL** forces DXGI to guarantee that the contents of each back buffer is preserved across `IDXGISwapChain::Present` calls, whereas **DXGI_SWAP_EFFECT_FLIP_DISCARD** doesn't provide this guarantee. The compositor, under certain scenarios, can use DirectFlip, where it uses the application's back buffer as the entire display back buffer, which elides the cost of copying the application's back buffer into the final desktop back buffer. With **DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL** and **DXGI_SWAP_EFFECT_FLIP_DISCARD**, this optimization can occur when the application is the only item visible on the screen. However, even when the application is not the only visible item on the screen, if the flip model is **DXGI_SWAP_EFFECT_FLIP_DISCARD**, the compositor can in some scenarios still perform this optimization, by drawing other content onto the application's back buffer.

When you call [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) on a flip model swap chain (**DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL**) with 0 specified in the *SyncInterval* parameter, **IDXGISwapChain1::Present1**'s behavior is the same as the behavior of [Direct3D 9Ex](https://learn.microsoft.com/windows/win32/direct3darticles/direct3d-9ex-improvements)'s [IDirect3DDevice9Ex::PresentEx](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3ddevice9ex-presentex) with [D3DSWAPEFFECT_FLIPEX](https://learn.microsoft.com/windows/win32/direct3d9/d3dswapeffect) and [D3DPRESENT_FORCEIMMEDIATE](https://learn.microsoft.com/windows/win32/direct3d9/d3dpresent). That is, the runtime not only presents the next frame instead of any previously queued frames, it also terminates any remaining time left on the previously queued frames.

Regardless of whether the flip model is more efficient, an application still might choose the bitblt model because the bitblt model is the only way to mix GDI and DirectX presentation. In the flip model, the application must create the swap chain with [DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE](https://learn.microsoft.com/windows/win32/api/dxgi/ne-dxgi-dxgi_swap_chain_flag), and then must use [GetDC](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgisurface1-getdc) on the back buffer explicitly. After the first successful call to [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) on a flip-model swap chain, GDI no longer works with the [HWND](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types) that is associated with that swap chain, even after the destruction of the swap chain. This restriction even extends to methods like [ScrollWindowEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-scrollwindowex).

To display HDR swapchain buffer formats and color spaces, a flip model is required. Otherwise they get composed (and clipped) in SDR (sRGB with a 0-1 range).

For more info about the flip-model swap chain and optimizing presentation, see [Enhancing presentation with the flip model, dirty rectangles, and scrolled areas](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-1-2-presentation-improvements).

#### Examples

To create a swap chain in UWP, you just need to create a new instance of the DX11 template and look at the implementation of `DeviceResources::CreateWindowSizeDependentResources` in the [D3D12 samples](https://github.com/Microsoft/DirectX-Graphics-Samples).

``` syntax
DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {0};

       swapChainDesc.Width = lround(m_d3dRenderTargetSize.Width);    // Match the size of the window.
       swapChainDesc.Height = lround(m_d3dRenderTargetSize.Height);
       swapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;            // This is the most common swap chain format.
       swapChainDesc.Stereo = false;
       swapChainDesc.SampleDesc.Count = 1;                           // Don't use multi-sampling.
       swapChainDesc.SampleDesc.Quality = 0;
       swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
       swapChainDesc.BufferCount = 2;                                // Use double-buffering to minimize latency.
       swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;     // All Windows Store apps must use a flip effect.
       swapChainDesc.Flags = 2048;
       swapChainDesc.Scaling = scaling;
       swapChainDesc.AlphaMode = DXGI_ALPHA_MODE_IGNORE;

       // This sequence obtains the DXGI factory that was used to create the Direct3D device above.
       ComPtr<IDXGIDevice3> dxgiDevice;
       DX::ThrowIfFailed(m_d3dDevice.As(&dxgiDevice));

       ComPtr<IDXGIAdapter> dxgiAdapter;
       DX::ThrowIfFailed(dxgiDevice->GetAdapter(&dxgiAdapter));

       ComPtr<IDXGIFactory4> dxgiFactory;
       DX::ThrowIfFailed(dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory)));

       ComPtr<IDXGISwapChain1> swapChain;
       DX::ThrowIfFailed(
              dxgiFactory->CreateSwapChainForCoreWindow(
                     m_d3dDevice.Get(),
                     reinterpret_cast<IUnknown*>(m_window.Get()),
                     &swapChainDesc,
                     nullptr,
                     &swapChain
                     )
              );

```

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/win32/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)

[For best performance, use DXGI flip model](https://devblogs.microsoft.com/directx/dxgi-flip-model/)