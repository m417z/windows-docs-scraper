# IDXGIFactory::CreateSwapChain

## Description

[Starting with Direct3D 11.1, we recommend not to use **CreateSwapChain** anymore to create a swap chain. Instead, use [CreateSwapChainForHwnd](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd), [CreateSwapChainForCoreWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcorewindow), or [CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition) depending on how you want to create the swap chain.]

Creates a swap chain.

## Parameters

### `pDevice` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

For Direct3D 11, and earlier versions of Direct3D, this is a pointer to the Direct3D device for the swap chain. For Direct3D 12 this is a pointer to a direct command queue (refer to [ID3D12CommandQueue](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandqueue)) . This parameter cannot be **NULL**.

### `pDesc` [in]

Type: **[DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_swap_chain_desc)***

A pointer to a [DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_swap_chain_desc) structure for the swap-chain description. This parameter cannot be **NULL**.

### `ppSwapChain` [out]

Type: **[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)****

A pointer to a variable that receives a pointer to the [IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain) interface for the swap chain that **CreateSwapChain** creates.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

[DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if *pDesc* or *ppSwapChain* is **NULL**, DXGI_STATUS_OCCLUDED if you request full-screen mode and it is unavailable, or E_OUTOFMEMORY. Other error codes defined by the type of device passed in may also be returned.

## Remarks

**Note** If you call this API in a Session 0 process, it returns [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

If you attempt to create a swap chain in full-screen mode, and full-screen mode is unavailable, the swap chain will be created in windowed mode and DXGI_STATUS_OCCLUDED will be returned.

If the buffer width or the buffer height is zero, the sizes will be inferred from the output window size in the swap-chain description.

Because the target output can't be chosen explicitly when the swap chain is created, we recommend not to create a full-screen swap chain. This can reduce presentation performance if the swap chain size and the output window size do not match. Here are two ways to ensure that the sizes match:

* Create a windowed swap chain and then set it full-screen using [IDXGISwapChain::SetFullscreenState](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-setfullscreenstate).
* Save a pointer to the swap chain immediately after creation, and use it to get the output window size during a WM_SIZE event. Then resize the swap chain buffers (with [IDXGISwapChain::ResizeBuffers](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-resizebuffers)) during the transition from windowed to full-screen.

If the swap chain is in full-screen mode, before you release it you must use [SetFullscreenState](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-setfullscreenstate) to switch it to windowed mode. For more information about releasing a swap chain, see the "Destroying a Swap Chain" section of [DXGI Overview](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-programming-guide-dxgi).

After the runtime renders the initial frame in full screen, the runtime might unexpectedly exit full screen during a call to [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present). To work around this issue, we recommend that you execute the following code right after you call **CreateSwapChain** to create a full-screen swap chain (**Windowed** member of [DXGI_SWAP_CHAIN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_swap_chain_desc) set to **FALSE**).

```

// Detect if newly created full-screen swap chain isn't actually full screen.
IDXGIOutput* pTarget; BOOL bFullscreen;
if (SUCCEEDED(pSwapChain->GetFullscreenState(&bFullscreen, &pTarget)))
{
   pTarget->Release();
}
else
   bFullscreen = FALSE;
// If not full screen, enable full screen again.
if (!bFullscreen)
{
   ShowWindow(hWnd, SW_MINIMIZE);
   ShowWindow(hWnd, SW_RESTORE);
   pSwapChain->SetFullscreenState(TRUE, NULL);
}

```

You can specify [DXGI_SWAP_EFFECT](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect) and [DXGI_SWAP_CHAIN_FLAG](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_chain_flag) values in the swap-chain description that *pDesc* points to. These values allow you to use features like flip-model presentation and content protection by using pre-Windows 8 APIs.

However, to use stereo presentation and to change resize behavior for the flip model, applications must use the [IDXGIFactory2::CreateSwapChainForHwnd](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd) method. Otherwise, the back-buffer contents implicitly scale to fit the presentation target size; that is, you can't turn off scaling.

### Notes for Windows Store apps

If a Windows Store app calls **CreateSwapChain** with full screen specified, **CreateSwapChain** fails.

Windows Store apps call the [IDXGIFactory2::CreateSwapChainForCoreWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcorewindow) method to create a swap chain.

For info about how to choose a format for the swap chain's back buffer, see [Converting data for the color space](https://learn.microsoft.com/windows/desktop/direct3ddxgi/converting-data-color-space).

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[For best performance, use DXGI flip model](https://learn.microsoft.com/windows/desktop/direct3ddxgi/for-best-performance--use-dxgi-flip-model)

[IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory)