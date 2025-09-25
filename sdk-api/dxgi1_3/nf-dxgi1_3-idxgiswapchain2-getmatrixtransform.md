## Description

Gets the transform matrix that will be applied to a composition swap chain upon the next present.

Starting with Windows 8.1, Windows Store apps are able to place DirectX swap chain visuals in XAML pages using the [SwapChainPanel](https://learn.microsoft.com/uwp/api/windows.ui.xaml.controls.swapchainpanel) element, which can be placed and sized arbitrarily. This exposes the DirectX swap chain visuals to touch scaling and translation scenarios using touch UI. The **GetMatrixTransform** and [SetMatrixTransform](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-setmatrixtransform) methods are used to synchronize scaling of the DirectX swap chain with its associated **SwapChainPanel** element. Only simple scale/translation elements in the matrix are allowed – the call will fail if the matrix contains skew/rotation elements.

## Parameters

### `pMatrix`

[out]

The transform matrix currently used for swap chain scaling and translation.

## Return value

**GetMatrixTransform** returns:

* S_OK if it successfully retrieves the transform matrix.
* DXGI_ERROR_INVALID_CALL if the method is called on a swap chain that was not created with [CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition).
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[IDXGISwapChain2](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgiswapchain2)

[SetMatrixTransform](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-setmatrixtransform)