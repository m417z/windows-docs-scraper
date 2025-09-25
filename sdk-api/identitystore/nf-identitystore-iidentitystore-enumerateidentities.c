HRESULT EnumerateIdentities(
  [in]           const IDENTITY_TYPE eIdentityType,
  [in, optional] const PROPERTYKEY   *pFilterkey,
  [in, optional] const PROPVARIANT   *pFilterPropVarValue,
  [out]          IEnumUnknown        **ppIdentityEnum
);