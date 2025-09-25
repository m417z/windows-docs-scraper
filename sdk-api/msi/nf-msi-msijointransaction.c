UINT MsiJoinTransaction(
  [in]  MSIHANDLE hTransactionHandle,
  [in]  DWORD     dwTransactionAttributes,
  [out] HANDLE    *phChangeOfOwnerEvent
);