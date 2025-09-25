HRESULT D3D11CreateDeviceAndSwapChain(
  [in, optional]  IDXGIAdapter               *pAdapter,
                  D3D_DRIVER_TYPE            DriverType,
                  HMODULE                    Software,
                  UINT                       Flags,
  [in, optional]  const D3D_FEATURE_LEVEL    *pFeatureLevels,
                  UINT                       FeatureLevels,
                  UINT                       SDKVersion,
  [in, optional]  const DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
  [out, optional] IDXGISwapChain             **ppSwapChain,
  [out, optional] ID3D11Device               **ppDevice,
  [out, optional] D3D_FEATURE_LEVEL          *pFeatureLevel,
  [out, optional] ID3D11DeviceContext        **ppImmediateContext
);