HRESULT CreateTable(
  [in]  wchar_t          *path,
  [in]  BOOL             truncate,
  [in]  BYTE             *securityDescriptor,
  [out] RdcCreatedTables *isNew
);