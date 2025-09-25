HRESULT D3D12CreateDevice(
  [in, optional]  IUnknown          *pAdapter,
                  D3D_FEATURE_LEVEL MinimumFeatureLevel,
  [in]            REFIID            riid,
  [out, optional] void              **ppDevice
);