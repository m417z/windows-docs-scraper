NTDSAPI DWORD DsReplicaGetInfo2W(
  [in]           HANDLE            hDS,
  [in]           DS_REPL_INFO_TYPE InfoType,
  [in, optional] LPCWSTR           pszObject,
  [in, optional] UUID              *puuidForSourceDsaObjGuid,
  [in, optional] LPCWSTR           pszAttributeName,
  [in, optional] LPCWSTR           pszValue,
  [in]           DWORD             dwFlags,
  [in]           DWORD             dwEnumerationContext,
  [out]          VOID              **ppInfo
);