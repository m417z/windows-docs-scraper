UINT MsiBeginTransactionA(
  [in]  LPCSTR    szName,
  [in]  DWORD     dwTransactionAttributes,
  [out] MSIHANDLE *phTransactionHandle,
  [out] HANDLE    *phChangeOfOwnerEvent
);