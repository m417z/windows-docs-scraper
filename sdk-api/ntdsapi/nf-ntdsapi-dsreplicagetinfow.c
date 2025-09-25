NTDSAPI DWORD DsReplicaGetInfoW(
  [in]           HANDLE            hDS,
  [in]           DS_REPL_INFO_TYPE InfoType,
  [in, optional] LPCWSTR           pszObject,
  [in, optional] UUID              *puuidForSourceDsaObjGuid,
  [out]          VOID              **ppInfo
);