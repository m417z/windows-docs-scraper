LONG SCardReadCacheW(
  [in]  SCARDCONTEXT hContext,
  [in]  UUID         *CardIdentifier,
  [in]  DWORD        FreshnessCounter,
  [in]  LPWSTR       LookupName,
  [out] PBYTE        Data,
  [out] DWORD        *DataLen
);