HRESULT CreateStorageWithMetadata(
  [in]  DWORD         dwAttributes,
  [in]  LPCWSTR       pwszName,
  [in]  IWMDMMetaData *pMetadata,
  [in]  ULONGLONG     qwFileSize,
  [out] IMDSPStorage  **ppNewStorage
);