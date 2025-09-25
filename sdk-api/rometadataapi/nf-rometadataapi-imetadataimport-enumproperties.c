HRESULT EnumProperties(
  [in, out] HCORENUM      *phEnum,
  [in]      mdTypeDef     tkTypDef,
  [out]     mdProperty [] rgProperties,
  [in]      ULONG         cMax,
  [out]     ULONG         *pcProperties
);