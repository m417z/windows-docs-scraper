HRESULT FindItemByProperty(
  [in]  IRawElementProviderSimple *pStartAfter,
  [in]  PROPERTYID                propertyId,
  [in]  VARIANT                   value,
  [out] IRawElementProviderSimple **pFound
);