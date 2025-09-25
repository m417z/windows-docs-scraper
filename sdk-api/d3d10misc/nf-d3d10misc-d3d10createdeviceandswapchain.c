HRESULT D3D10CreateDeviceAndSwapChain(
  [in]  IDXGIAdapter         *pAdapter,
  [in]  D3D10_DRIVER_TYPE    DriverType,
  [in]  HMODULE              Software,
  [in]  UINT                 Flags,
  [in]  UINT                 SDKVersion,
  [in]  DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
  [out] IDXGISwapChain       **ppSwapChain,
  [out] ID3D10Device         **ppDevice
);