HRESULT Insert3(
  [in]  UINT           fuMode,
  [in]  UINT           fuType,
  [in]  LPWSTR         pwszFileSource,
  [in]  LPWSTR         pwszFileDest,
  [in]  IWMDMOperation *pOperation,
  [in]  IWMDMProgress  *pProgress,
  [in]  IWMDMMetaData  *pMetaData,
  [in]  IUnknown       *pUnknown,
  [out] IWMDMStorage   **ppNewObject
);