HRESULT TransferToDevice(
  [in]  LPCWSTR        pwszSourceFilePath,
  [in]  IWMDMOperation *pSourceOperation,
  [in]  UINT           fuFlags,
  [in]  LPWSTR         pwszDestinationName,
  [in]  IWMDMMetaData  *pSourceMetaData,
  [in]  IWMDMProgress  *pTransferProgress,
  [out] IMDSPStorage   **ppNewObject
);