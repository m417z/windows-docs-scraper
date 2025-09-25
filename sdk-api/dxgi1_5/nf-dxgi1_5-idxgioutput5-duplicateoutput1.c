HRESULT DuplicateOutput1(
  [in]  IUnknown               *pDevice,
        UINT                   Flags,
  [in]  UINT                   SupportedFormatsCount,
  [in]  const DXGI_FORMAT      *pSupportedFormats,
  [out] IDXGIOutputDuplication **ppOutputDuplication
);