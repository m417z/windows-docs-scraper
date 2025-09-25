HRESULT FindClosestMatchingMode(
  [in]           const DXGI_MODE_DESC *pModeToMatch,
  [out]          DXGI_MODE_DESC       *pClosestMatch,
  [in, optional] IUnknown             *pConcernedDevice
);