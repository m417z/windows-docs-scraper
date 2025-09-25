HRESULT EnumMembers(
  [in, out] HCORENUM   *phEnum,
  [in]      mdTypeDef  tkTypeDef,
  [out]     mdToken [] rgMembers,
  [in]      ULONG      cMax,
  [out]     ULONG      *pcTokens
);