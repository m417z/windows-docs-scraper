BOOL SetTransactionInformation(
  [in]           HANDLE TransactionHandle,
  [in, optional] DWORD  IsolationLevel,
  [in, optional] DWORD  IsolationFlags,
  [in, optional] DWORD  Timeout,
  [in, optional] LPWSTR Description
);