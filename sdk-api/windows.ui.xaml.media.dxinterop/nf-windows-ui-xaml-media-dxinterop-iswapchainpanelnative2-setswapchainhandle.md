# ISwapChainPanelNative2::xaml

## Description

Sets the DirectX swap chain for [SwapChainPanel](https://learn.microsoft.com/uwp/api/windows.ui.xaml.controls.swapchainpanel) using a handle to the swap chain.

## Parameters

### `swapChainHandle` [in]

A shared handle to a swap chain.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

SetSwapChain(HANDLE swapChainHandle) allows a swap chain to be rendered by referencing a shared handle to the swap chain.
This enables scenarios where a swap chain is created in one process and needs to be passed to another process.

XAML supports setting a DXGI swap chain as the content of a SwapChainPanel element. Apps accomplish this by querying for
the [ISwapChainPanelNative](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-iswapchainpanelnative) interface from a SwapChainPanel instance and calling [SetSwapChain(IDXGISwapChain *swapChain)](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nf-windows-ui-xaml-media-dxinterop-iswapchainpanelnative-setswapchain).

This process works for pointers to in process swap chains. However, this doesn’t work for VoIP apps, which use a two-process model to enable continuing calls on a background process
when a foreground process is suspended or shut down. This two-process implementation requires the ability to pass a shared handle to a swap chain, rather than a pointer, created on the
background process to the foreground process to be rendered in a XAML SwapChainPanel in the foreground app.

```cpp

<!-- XAML markup -->
<Page>
 <SwapChainPanel x:Name=”captureStreamDisplayPanel” />
</Page>

// Definitions
ComPtr<IDXGISwapChain1> m_swapChain;
HANDLE m_swapChainHandle;
ComPtr<ID3D11Device> m_d3dDevice;
ComPtr<IDXGIAdapter> dxgiAdapter;
ComPtr<IDXGIFactory2> dxgiFactory;
ComPtr<IDXGIFactoryMedia> dxgiFactoryMedia;
ComPtr<IDXGIDevice> dxgiDevice;
DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {0};

// Get DXGI factory (assume standard boilerplate has created D3D11Device)
m_d3dDevice.As(&dxgiDevice);
dxgiDevice->GetAdapter(&dxgiAdapter);
dxgiAdapter->GetParent(__uuidof(IDXGIFactory2), &dxgiFactory);

// Create swap chain and get handle
DCompositionCreateSurfaceHandle(GENERIC_ALL, nullptr, &m_swapChainHandle);
dxgiFactory.As(&dxgiFactoryMedia);
dxgiFactoryMedia->CreateSwapChainForCompositionSurfaceHandle(
  m_d3dDevice.Get(),
  m_swapChainHandle,
  &swapChainDesc,
  nullptr,
  &m_swapChain
);

// Set swap chain to display in a SwapChainPanel
ComPtr<ISwapChainPanelNative2> panelNative;
reinterpret_cast<IUnknown*>(captureStreamDisplayPanel)->QueryInterface(IID_PPV_ARGS(&panelNative)));
panelNative->SetSwapChainHandle(m_swapChainHandle);
	
```

## See also

[ISwapChainPanelNative2](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.media.dxinterop/nn-windows-ui-xaml-media-dxinterop-iswapchainpanelnative2)