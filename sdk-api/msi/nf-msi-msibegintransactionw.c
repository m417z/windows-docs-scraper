UINT MsiBeginTransactionW(
  [in]  LPCWSTR   szName,
  [in]  DWORD     dwTransactionAttributes,
  [out] MSIHANDLE *phTransactionHandle,
  [out] HANDLE    *phChangeOfOwnerEvent
);