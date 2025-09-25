NTDSAPI DWORD DsReplicaSyncA(
  [in] HANDLE     hDS,
  [in] LPCSTR     NameContext,
  [in] const UUID *pUuidDsaSrc,
  [in] ULONG      Options
);