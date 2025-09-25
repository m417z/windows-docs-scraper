HRESULT EnumFields(
  [in, out] HCORENUM      *phEnum,
  [in]      mdTypeDef     tkTypeDef,
  [out]     mdFieldDef [] rgFields,
  [in]      ULONG         cMax,
  [out]     ULONG         *pcTokens
);