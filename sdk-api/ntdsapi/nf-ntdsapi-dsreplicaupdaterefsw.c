NTDSAPI DWORD DsReplicaUpdateRefsW(
  [in] HANDLE     hDS,
  [in] LPCWSTR    NameContext,
  [in] LPCWSTR    DsaDest,
  [in] const UUID *pUuidDsaDest,
  [in] ULONG      Options
);