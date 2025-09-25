HRESULT EnumParams(
  [in, out] HCORENUM      *phEnum,
  [in]      mdMethodDef   tkMethodDef,
  [out]     mdParamDef [] rParams,
  [in]      ULONG         cMax,
  [out]     ULONG         *pcTokens
);