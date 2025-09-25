HRESULT EnumMethodsWithName(
  [in, out] HCORENUM       *phEnum,
  [in]      mdTypeDef      tkTypeDef,
  [in]      LPCWSTR        szName,
  [out]     mdMethodDef [] rgMethods,
  [in]      ULONG          cMax,
  [out]     ULONG          *pcTokens
);