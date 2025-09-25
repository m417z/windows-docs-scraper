HRESULT CreateTableIndirect(
  [in]  IRdcFileWriter   *fileIdFile,
  [in]  BOOL             truncate,
  [in]  DWORD            recordSize,
  [out] RdcCreatedTables *isNew
);