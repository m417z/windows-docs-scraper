# IDXGIFactory2::CreateSwapChainForHwnd

## Description

Creates a swap chain that is associated with an [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) handle to the output window for the swap chain.

## Parameters

### `pDevice` [in]

For Direct3D 11, and earlier versions of Direct3D, this is a pointer to the Direct3D device for the swap chain. For Direct3D 12 this is a pointer to a direct command queue (refer to [ID3D12CommandQueue](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandqueue)). This parameter cannot be **NULL**.

### `hWnd` [in]

The [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) handle that is associated with the swap chain that **CreateSwapChainForHwnd** creates. This parameter cannot be **NULL**.

### `pDesc` [in]

A pointer to a [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) structure for the swap-chain description. This parameter cannot be **NULL**.

### `pFullscreenDesc` [in, optional]

A pointer to a [DXGI_SWAP_CHAIN_FULLSCREEN_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_fullscreen_desc) structure for the description of a full-screen swap chain. You can optionally set this parameter to create a full-screen swap chain. Set it to **NULL** to create a windowed swap chain.

### `pRestrictToOutput` [in, optional]

A pointer to the [IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput) interface for the output to restrict content to. You must also pass the [DXGI_PRESENT_RESTRICT_TO_OUTPUT](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present) flag in a [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) call to force the content to appear blacked out on any other output. If you want to restrict the content to a different output, you must create a new swap chain. However, you can conditionally restrict content based on the **DXGI_PRESENT_RESTRICT_TO_OUTPUT** flag.

Set this parameter to **NULL** if you don't want to restrict content to an output target.

### `ppSwapChain` [out]

A pointer to a variable that receives a pointer to the [IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1) interface for the swap chain that **CreateSwapChainForHwnd** creates.

## Return value

**CreateSwapChainForHwnd** returns:

* S_OK if it successfully created a swap chain.
* E_OUTOFMEMORY if memory is unavailable to complete the operation.
* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if the calling application provided invalid data, for example, if *pDesc* or *ppSwapChain* is **NULL**, or *pDesc* data members are invalid.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic that are defined by the type of device that you pass to *pDevice*.

**Platform Update for Windows 7:** [DXGI_SCALING_NONE](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_scaling) is not supported on Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed and causes **CreateSwapChainForHwnd** to return DXGI_ERROR_INVALID_CALL when called. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

**Note** Do not use this method in Windows Store apps. Instead, use [IDXGIFactory2::CreateSwapChainForCoreWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcorewindow).

If you specify the width, height, or both (**Width** and **Height** members of [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) that *pDesc* points to) of the swap chain as zero, the runtime obtains the size from the output window that the *hWnd* parameter specifies.

You can subsequently call the [IDXGISwapChain1::GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-getdesc1) method to retrieve the assigned width or height value.

Because you can associate only one flip presentation model swap chain at a time with an [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types), the Microsoft Direct3D 11 policy of deferring the destruction of objects can cause problems if you attempt to destroy a flip presentation model swap chain and replace it with another swap chain. For more info about this situation, see [Deferred Destruction Issues with Flip Presentation Swap Chains](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-flush).

For info about how to choose a format for the swap chain's back buffer, see [Converting data for the color space](https://learn.microsoft.com/windows/desktop/direct3ddxgi/converting-data-color-space).

## See also

[For best performance, use DXGI flip model](https://learn.microsoft.com/windows/desktop/direct3ddxgi/for-best-performance--use-dxgi-flip-model)

[IDXGIFactory2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgifactory2)