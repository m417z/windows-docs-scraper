HRESULT GetMediaComponentPackageInfo(
  [in]  bool                                                                                               trustedOnly,
  [in]  HSTRING                                                                                            category,
  [out] ABI::Windows::Foundation::Collections::IVector<ABI::Windows::Foundation::Collections::IPropertySet *>**codecPropertiesVector
);