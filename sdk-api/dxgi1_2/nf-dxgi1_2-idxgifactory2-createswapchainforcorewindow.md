# IDXGIFactory2::CreateSwapChainForCoreWindow

## Description

Creates a swap chain that is associated with the [CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow) object for the output window for the swap chain.

## Parameters

### `pDevice` [in]

For Direct3D 11, and earlier versions of Direct3D, this is a pointer to the Direct3D device for the swap chain. For Direct3D 12 this is a pointer to a direct command queue (refer to [ID3D12CommandQueue](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandqueue)). This parameter cannot be **NULL**.

### `pWindow` [in]

A pointer to the [CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow) object that is associated with the swap chain that **CreateSwapChainForCoreWindow** creates.

### `pDesc` [in]

A pointer to a [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) structure for the swap-chain description. This parameter cannot be **NULL**.

### `pRestrictToOutput` [in, optional]

A pointer to the [IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput) interface that the swap chain is restricted to. If the swap chain is moved to a different output, the content is black. You can optionally set this parameter to an output target that uses [DXGI_PRESENT_RESTRICT_TO_OUTPUT](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present) to restrict the content on this output. If you do not set this parameter to restrict content on an output target, you can set it to **NULL**.

### `ppSwapChain` [out]

A pointer to a variable that receives a pointer to the [IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1) interface for the swap chain that **CreateSwapChainForCoreWindow** creates.

## Return value

**CreateSwapChainForCoreWindow** returns:

* S_OK if it successfully created a swap chain.
* E_OUTOFMEMORY if memory is unavailable to complete the operation.
* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if the calling application provided invalid data, for example, if *pDesc* or *ppSwapChain* is **NULL**.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic that are defined by the type of device that you pass to *pDevice*.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **CreateSwapChainForCoreWindow** fails with E_NOTIMPL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

**Note** Use this method in Windows Store apps rather than [IDXGIFactory2::CreateSwapChainForHwnd](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd).

If you specify the width, height, or both (**Width** and **Height** members of [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) that *pDesc* points to) of the swap chain as zero, the runtime obtains the size from the output window that the *pWindow* parameter specifies.

You can subsequently call the [IDXGISwapChain1::GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-getdesc1) method to retrieve the assigned width or height value.

Because you can associate only one flip presentation model swap chain (per layer) at a time with a [CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow), the Microsoft Direct3D 11 policy of deferring the destruction of objects can cause problems if you attempt to destroy a flip presentation model swap chain and replace it with another swap chain. For more info about this situation, see [Deferred Destruction Issues with Flip Presentation Swap Chains](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-flush).

For info about how to choose a format for the swap chain's back buffer, see [Converting data for the color space](https://learn.microsoft.com/windows/desktop/direct3ddxgi/converting-data-color-space).

### Overlapping swap chains

Starting with Windows 8.1, it is possible to create an additional swap chain in the foreground layer. A foreground swap chain can be used to render UI elements at native resolution while scaling up real-time rendering in the background swap chain (such as gameplay). This enables scenarios where lower resolution rendering is required for faster fill rates, but without sacrificing UI quality.

Foreground swap chains are created by setting the **DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER** swap chain flag in the [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) that *pDesc* points to. Foreground swap chains must also use the **DXGI_ALPHA_MODE_PREMULTIPLIED** alpha mode, and must use **DXGI_SCALING_NONE**. Premultiplied alpha means that each pixel's color values are expected to be already multiplied by the alpha value before the frame is presented. For example, a 100% white BGRA pixel at 50% alpha is set to (0.5, 0.5, 0.5, 0.5). The alpha premultiplication step can be done in the output-merger stage by applying an app blend state (see [ID3D11BlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11blendstate)) with the [D3D11_RENDER_TARGET_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_render_target_blend_desc) structure's **SrcBlend** field set to **D3D11_SRC_ALPHA**. If the alpha premultiplication step is not done, colors on the foreground swap chain will be brighter than expected.

The foreground swap chain will use multiplane overlays if supported by the hardware. Call [IDXGIOutput2::SupportsOverlays](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgioutput2-supportsoverlays) to query the adapter for overlay support.

The following example creates a foreground swap chain for a CoreWindow:

```cpp

DXGI_SWAP_CHAIN_DESC1 swapChainDesc = { 0 };

swapChainDesc.Width = static_cast<UINT>(m_d3dRenderTargetSize.Width);
swapChainDesc.Height = static_cast<UINT>(m_d3dRenderTargetSize.Height);
swapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
swapChainDesc.Stereo = false;
swapChainDesc.SampleDesc.Count = 1; // Don't use multi-sampling.
swapChainDesc.SampleDesc.Quality = 0;
swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
swapChainDesc.BufferCount = 2;
swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER;
swapChainDesc.AlphaMode = DXGI_ALPHA_MODE_PREMULTIPLIED;
swapChainDesc.Scaling = DXGI_SCALING_NONE;

ComPtr<IDXGISwapChain1> swapChain;
HRESULT hr = dxgiFactory->CreateSwapChainForCoreWindow(
    m_d3dDevice.Get(),
    reinterpret_cast<IUnknown*>(m_window.Get()),
    &swapChainDesc,
    nullptr,
    &swapChain
    );
```

Present both swap chains together after rendering is complete.

The following example presents both swap chains:

```cpp

HRESULT hr = m_swapChain->Present(1, 0);

if (SUCCEEDED(hr) && m_foregroundSwapChain)
{
    m_foregroundSwapChain->Present(1, 0);
}
```

## See also

[CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow)

[For best performance, use DXGI flip model](https://learn.microsoft.com/windows/desktop/direct3ddxgi/for-best-performance--use-dxgi-flip-model)

[IDXGIFactory2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgifactory2)