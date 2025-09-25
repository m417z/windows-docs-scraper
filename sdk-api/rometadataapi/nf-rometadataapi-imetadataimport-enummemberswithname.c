HRESULT EnumMembersWithName(
  [in, out] HCORENUM   *phEnum,
  [in]      mdTypeDef  tkTypeDef,
  [in]      LPCWSTR    szName,
  [out]     mdToken [] rgMembers,
  [in]      ULONG      cMax,
  [out]     ULONG      *pcTokens
);