NTDSAPI DWORD DsReplicaVerifyObjectsA(
  [in] HANDLE     hDS,
  [in] LPCSTR     NameContext,
  [in] const UUID *pUuidDsaSrc,
  [in] ULONG      ulOptions
);