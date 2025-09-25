# ISwapChainPanelNative::xaml

## Description

Sets the DirectX swap chain for [SwapChainPanel](https://learn.microsoft.com/uwp/api/windows.ui.xaml.controls.swapchainpanel).

## Parameters

### `swapChain` [in] [opt]

A configured [IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method has to be called on the UI thread the parent [SwapChainPanel](https://learn.microsoft.com/uwp/api/windows.ui.xaml.controls.swapchainpanel) belongs to. If called on another thread, it will return `0x8001010E` (`RPC_E_WRONG_THREAD`, "The application called an interface that was marshaled for a different thread").

When called, this method will increment the reference count for the input [IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain) that is passed as input. This will in turn cause the reference count to the target graphics device in use (eg. an [ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device)) to be incremented as well. In order to ensure these references are released immediately when the panel is no longer needed, you can call `SetSwapChain` again passing a `null` pointer. This will ensure that all additional references to the object graph starting from the input [IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain) that had been added by the [SwapChainPanel](https://learn.microsoft.com/uwp/api/windows.ui.xaml.controls.swapchainpanel) instance will be removed. This is especially important to ensure the device in use can properly be released, for instance to recover from device lost scenarios.

## See also

[ISwapChainPanelNative](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-iswapchainpanelnative)