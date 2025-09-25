HRESULT D3D10CreateDeviceAndSwapChain1(
  [in]  IDXGIAdapter         *pAdapter,
  [in]  D3D10_DRIVER_TYPE    DriverType,
  [in]  HMODULE              Software,
  [in]  UINT                 Flags,
  [in]  D3D10_FEATURE_LEVEL1 HardwareLevel,
  [in]  UINT                 SDKVersion,
  [in]  DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
  [out] IDXGISwapChain       **ppSwapChain,
  [out] ID3D10Device1        **ppDevice
);