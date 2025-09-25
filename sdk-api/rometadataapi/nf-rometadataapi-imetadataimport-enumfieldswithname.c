HRESULT EnumFieldsWithName(
  [in, out] HCORENUM      *phEnum,
  [in]      mdTypeDef     tkTypeDef,
  [in]      LPCWSTR       szName,
  [out]     mdFieldDef [] rFields,
  [in]      ULONG         cMax,
  [out]     ULONG         *pcTokens
);