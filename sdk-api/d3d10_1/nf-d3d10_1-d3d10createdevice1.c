HRESULT D3D10CreateDevice1(
  [in]  IDXGIAdapter         *pAdapter,
  [in]  D3D10_DRIVER_TYPE    DriverType,
  [in]  HMODULE              Software,
  [in]  UINT                 Flags,
  [in]  D3D10_FEATURE_LEVEL1 HardwareLevel,
  [in]  UINT                 SDKVersion,
  [out] ID3D10Device1        **ppDevice
);