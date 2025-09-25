LONG SCardWriteCacheW(
  [in] SCARDCONTEXT hContext,
  [in] UUID         *CardIdentifier,
  [in] DWORD        FreshnessCounter,
  [in] LPWSTR       LookupName,
  [in] PBYTE        Data,
  [in] DWORD        DataLen
);