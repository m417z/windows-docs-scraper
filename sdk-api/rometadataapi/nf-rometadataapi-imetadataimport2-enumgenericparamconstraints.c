HRESULT EnumGenericParamConstraints(
  [in, out] HCORENUM                    *phEnum,
  [in]      mdGenericParam              tk,
  [out]     mdGenericParamConstraint [] rGenericParamConstraints,
  [in]      ULONG                       cMax,
  [out]     ULONG                       *pcGenericParamConstraints
);