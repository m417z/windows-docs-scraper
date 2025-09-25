HRESULT EnumMethodImpls(
  [in, out] HCORENUM   *phEnum,
  [in]      mdTypeDef  tkTypeDef,
  [out]     mdToken [] rMethodBody,
  [out]     mdToken [] rMethodDecl,
  [in]      ULONG      cMax,
  [out]     ULONG      *pcTokens
);