# IDXGISwapChain1::GetRestrictToOutput

## Description

Gets the output (the display monitor) to which you can restrict the contents of a present operation.

## Parameters

### `ppRestrictToOutput` [out]

 A pointer to a buffer that receives a pointer to the [IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput) interface for the restrict-to output. An application passes this pointer to **IDXGIOutput** in a call to the [IDXGIFactory2::CreateSwapChainForHwnd](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd), [IDXGIFactory2::CreateSwapChainForCoreWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcorewindow), or [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition) method to create the swap chain.

## Return value

Returns S_OK if the restrict-to output was successfully retrieved; otherwise, returns E_INVALIDARG if the pointer is invalid.

## Remarks

If the method succeeds, the runtime fills the buffer at *ppRestrictToOutput* with a pointer to the restrict-to output interface. This restrict-to output interface has its reference count incremented. When you are finished with it, be sure to release the interface to avoid a memory leak.

The output is also owned by the adapter on which the swap chain's device was created.

## See also

[IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1)