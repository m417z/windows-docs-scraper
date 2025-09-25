HRESULT EnumModuleRefs(
  [in, out] HCORENUM       *phEnum,
  [out]     mdModuleRef [] rgModuleRefs,
  [in]      ULONG          cMax,
  [out]     ULONG          *pcModuleRefs
);