NTDSAPI DWORD DsReplicaSyncW(
  [in] HANDLE     hDS,
  [in] LPCWSTR    NameContext,
  [in] const UUID *pUuidDsaSrc,
  [in] ULONG      Options
);