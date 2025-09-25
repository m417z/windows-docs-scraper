# IDXGIFactoryMedia::CreateSwapChainForCompositionSurfaceHandle

## Description

Creates a YUV swap chain for an existing [DirectComposition](https://learn.microsoft.com/windows/desktop/directcomp/reference) surface handle.

## Parameters

### `pDevice` [in]

A pointer to the Direct3D device for the swap chain. This parameter cannot be **NULL**. Software drivers, like [D3D_DRIVER_TYPE_REFERENCE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type), are not supported for composition swap chains.

### `hSurface` [in, optional]

A handle to an existing [DirectComposition](https://learn.microsoft.com/windows/desktop/directcomp/reference) surface. This parameter cannot be **NULL**.

### `pDesc` [in]

A pointer to a [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) structure for the swap-chain description. This parameter cannot be **NULL**.

### `pRestrictToOutput` [in, optional]

A pointer to the [IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput) interface for the swap chain to restrict content to. If the swap chain is moved to a different output, the content is black. You can optionally set this parameter to an output target that uses [DXGI_PRESENT_RESTRICT_TO_OUTPUT](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present) to restrict the content on this output. If the swap chain is moved to a different output, the content is black.

You must also pass the [DXGI_PRESENT_RESTRICT_TO_OUTPUT](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-present) flag in a present call to force the content to appear blacked out on any other output. If you want to restrict the content to a different output, you must create a new swap chain. However, you can conditionally restrict content based on the **DXGI_PRESENT_RESTRICT_TO_OUTPUT** flag.

Set this parameter to **NULL** if you don't want to restrict content to an output target.

### `ppSwapChain` [out]

A pointer to a variable that receives a pointer to the [IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1) interface for the swap chain that this method creates.

## Return value

**CreateSwapChainForCompositionSurfaceHandle** returns:

* S_OK if it successfully created a swap chain.
* E_OUTOFMEMORY if memory is unavailable to complete the operation.
* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if the calling application provided invalid data, for example, if *pDesc*, *pYuvDecodeBuffers*, or *ppSwapChain* is **NULL**.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic that are defined by the type of device that you pass to *pDevice*.

## See also

[For best performance, use DXGI flip model](https://learn.microsoft.com/windows/desktop/direct3ddxgi/for-best-performance--use-dxgi-flip-model)

[IDXGIFactoryMedia](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgifactorymedia)