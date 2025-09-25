HRESULT EnumAssemblyRefs(
  [in, out] HCORENUM         *phEnum,
  [out]     mdAssemblyRef [] rAssemblyRefs,
  [in]      ULONG            cMax,
  [out]     ULONG            *pcTokens
);