HRESULT D3D10CreateDevice(
  [in]  IDXGIAdapter      *pAdapter,
  [in]  D3D10_DRIVER_TYPE DriverType,
  [in]  HMODULE           Software,
  [in]  UINT              Flags,
  [in]  UINT              SDKVersion,
  [out] ID3D10Device      **ppDevice
);