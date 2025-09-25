LONG SCardReadCacheA(
  [in]  SCARDCONTEXT hContext,
  [in]  UUID         *CardIdentifier,
  [in]  DWORD        FreshnessCounter,
  [in]  LPSTR        LookupName,
  [out] PBYTE        Data,
  [out] DWORD        *DataLen
);