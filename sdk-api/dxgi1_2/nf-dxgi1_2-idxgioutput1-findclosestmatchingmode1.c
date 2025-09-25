HRESULT FindClosestMatchingMode1(
  [in]           const DXGI_MODE_DESC1 *pModeToMatch,
  [out]          DXGI_MODE_DESC1       *pClosestMatch,
  [in, optional] IUnknown              *pConcernedDevice
);