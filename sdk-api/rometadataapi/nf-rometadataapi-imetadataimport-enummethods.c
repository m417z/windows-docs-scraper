HRESULT EnumMethods(
  [in, out] HCORENUM       *phEnum,
  [in]      mdTypeDef      tkTypeDef,
  [out]     mdMethodDef [] rgMethods,
  [in]      ULONG          cMax,
  [out]     ULONG          *pcTokens
);