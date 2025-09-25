HRESULT EnumUnresolvedMethods(
  [in, out] HCORENUM   *phEnum,
  [out]     mdToken [] rgMethods,
  [in]      ULONG      cMax,
  [out]     ULONG      *pcTokens
);