HRESULT EnumCustomAttributes(
  [in, out] HCORENUM             *phEnum,
  [in]      mdToken              tk,
  [in]      mdToken              tkType,
  [out]     mdCustomAttribute [] rgCustomAttributes,
  [in]      ULONG                cMax,
  [out]     ULONG                *pcCustomAttributes
);