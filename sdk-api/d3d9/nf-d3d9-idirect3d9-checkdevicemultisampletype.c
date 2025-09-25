HRESULT CheckDeviceMultiSampleType(
  [in]  UINT                Adapter,
  [in]  D3DDEVTYPE          DeviceType,
  [in]  D3DFORMAT           SurfaceFormat,
  [in]  BOOL                Windowed,
  [in]  D3DMULTISAMPLE_TYPE MultiSampleType,
  [out] DWORD               *pQualityLevels
);