HRESULT EnumPermissionSets(
  [in, out] HCORENUM        *phEnum,
  [in]      mdToken         tk,
  [in]      DWORD           dwActions,
  [out]     mdPermission [] rPermission,
  [in]      ULONG           cMax,
  [out]     ULONG           *pcTokens
);