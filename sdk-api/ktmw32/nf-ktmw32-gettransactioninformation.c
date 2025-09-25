BOOL GetTransactionInformation(
  [in]            HANDLE TransactionHandle,
  [out, optional] PDWORD Outcome,
  [out, optional] PDWORD IsolationLevel,
  [out, optional] PDWORD IsolationFlags,
  [out, optional] PDWORD Timeout,
  [in]            DWORD  BufferLength,
  [out, optional] LPWSTR Description
);