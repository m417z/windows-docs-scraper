## Description

Sets the transform matrix that will be applied to a composition swap chain upon the next present.

Starting with Windows 8.1, Windows Store apps are able to place DirectX swap chain visuals in XAML pages using the [SwapChainPanel](https://learn.microsoft.com/uwp/api/windows.ui.xaml.controls.swapchainpanel) element, which can be placed and sized arbitrarily. This exposes the DirectX swap chain visuals to touch scaling and translation scenarios using touch UI. The [GetMatrixTransform](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-getmatrixtransform) and **SetMatrixTransform** methods are used to synchronize scaling of the DirectX swap chain with its associated **SwapChainPanel** element. Only simple scale/translation elements in the matrix are allowed – the call will fail if the matrix contains skew/rotation elements.

## Parameters

### `pMatrix`

The transform matrix to use for swap chain scaling and translation. This function can only be used with composition swap chains created by [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition). Only scale and translation components are allowed in the matrix.

## Return value

**SetMatrixTransform** returns:

* S_OK if it successfully retrieves the transform matrix.
* E_INVALIDARG if the *pMatrix* parameter is incorrect, for example, *pMatrix* is NULL or the matrix represented by [DXGI_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/ns-dxgi1_3-dxgi_matrix_3x2_f) includes components other than scale and translation.
* DXGI_ERROR_INVALID_CALL if the method is called on a swap chain that was not created with [CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition).
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[GetMatrixTransform](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-getmatrixtransform)

[IDXGISwapChain2](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgiswapchain2)