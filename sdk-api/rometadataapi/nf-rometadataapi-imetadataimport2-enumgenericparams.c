HRESULT EnumGenericParams(
  [in, out] HCORENUM          *phEnum,
  [in]      mdToken           tk,
  [out]     mdGenericParam [] rGenericParams,
  [in]      ULONG             cMax,
  [out]     ULONG             *pcGenericParams
);