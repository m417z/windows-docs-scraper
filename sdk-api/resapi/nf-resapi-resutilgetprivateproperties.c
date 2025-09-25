DWORD ResUtilGetPrivateProperties(
  [in]  HKEY    hkeyClusterKey,
  [out] PVOID   pOutPropertyList,
  [in]  DWORD   cbOutPropertyListSize,
  [out] LPDWORD pcbBytesReturned,
  [out] LPDWORD pcbRequired
);