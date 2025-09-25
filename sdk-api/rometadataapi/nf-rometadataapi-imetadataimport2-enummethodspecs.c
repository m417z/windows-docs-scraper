HRESULT EnumMethodSpecs(
  [in, out] HCORENUM        *phEnum,
  [in]      mdToken         tk,
  [out]     mdMethodSpec [] rMethodSpecs,
  [in]      ULONG           cMax,
  [out]     ULONG           *pcMethodSpecs
);