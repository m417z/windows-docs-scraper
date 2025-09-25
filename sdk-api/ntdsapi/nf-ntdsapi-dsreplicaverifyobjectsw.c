NTDSAPI DWORD DsReplicaVerifyObjectsW(
  [in] HANDLE     hDS,
  [in] LPCWSTR    NameContext,
  [in] const UUID *pUuidDsaSrc,
  [in] ULONG      ulOptions
);