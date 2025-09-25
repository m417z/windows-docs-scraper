HRESULT Insert2(
  [in]  UINT           fuMode,
  [in]  LPWSTR         pwszFileSource,
  [in]  LPWSTR         pwszFileDest,
  [in]  IWMDMOperation *pOperation,
  [in]  IWMDMProgress  *pProgress,
  [in]  IUnknown       *pUnknown,
  [out] IWMDMStorage   **ppNewObject
);