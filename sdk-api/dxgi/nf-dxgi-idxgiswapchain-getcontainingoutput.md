# IDXGISwapChain::GetContainingOutput

## Description

Get the output (the display monitor) that contains the majority of the client area of the target window.

## Parameters

### `ppOutput` [out]

Type: **[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)****

A pointer to the output interface (see [IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

If the method succeeds, the output interface will be filled and its reference count incremented. When you are finished with it, be sure to release the interface to avoid a memory leak.

The output is also owned by the adapter on which the swap chain's device was created.

You cannot call **GetContainingOutput** on a swap chain that you created with [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition).

To determine the output corresponding to such a swap chain, you should call [IDXGIFactory::EnumAdapters](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgifactory-enumadapters) and then [IDXGIAdapter::EnumOutputs](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter-enumoutputs) to enumerate over all of the available outputs. You should then intersect the bounds of your [CoreWindow::Bounds](https://learn.microsoft.com/uwp/api/windows.ui.core.corewindow.bounds) with the desktop coordinates of each output, as reported by [DXGI_OUTPUT_DESC1::DesktopCoordinates](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/ns-dxgi1_6-dxgi_output_desc1) or [DXGI_OUTPUT_DESC::DesktopCoordinates](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_output_desc).

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)