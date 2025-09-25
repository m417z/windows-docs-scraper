DWORD McastEnumerateScopes(
  [in]      IP_ADDR_FAMILY     AddrFamily,
  [in]      BOOL               ReQuery,
  [in, out] PMCAST_SCOPE_ENTRY pScopeList,
  [in, out] PDWORD             pScopeLen,
  [out]     PDWORD             pScopeCount
);