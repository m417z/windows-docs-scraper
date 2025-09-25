HRESULT CreateTable(
  [in]  wchar_t          *path,
  [in]  BOOL             truncate,
  [in]  BYTE             *securityDescriptor,
  [in]  DWORD            recordSize,
  [out] RdcCreatedTables *isNew
);