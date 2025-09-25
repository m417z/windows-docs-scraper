LONG SCardWriteCacheA(
  [in] SCARDCONTEXT hContext,
  [in] UUID         *CardIdentifier,
  [in] DWORD        FreshnessCounter,
  [in] LPSTR        LookupName,
  [in] PBYTE        Data,
  [in] DWORD        DataLen
);