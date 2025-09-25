HANDLE CreateTransaction(
  [in, optional] LPSECURITY_ATTRIBUTES lpTransactionAttributes,
  [in, optional] LPGUID                UOW,
  [in, optional] DWORD                 CreateOptions,
  [in, optional] DWORD                 IsolationLevel,
  [in, optional] DWORD                 IsolationFlags,
  [in, optional] DWORD                 Timeout,
  [in, optional] LPWSTR                Description
);