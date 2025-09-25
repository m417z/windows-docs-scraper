NTDSAPI DWORD DsReplicaUpdateRefsA(
  [in] HANDLE     hDS,
  [in] LPCSTR     NameContext,
  [in] LPCSTR     DsaDest,
  [in] const UUID *pUuidDsaDest,
  [in] ULONG      Options
);