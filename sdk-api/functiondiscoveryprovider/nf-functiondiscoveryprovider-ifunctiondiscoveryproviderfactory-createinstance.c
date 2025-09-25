HRESULT CreateInstance(
  [in]  const WCHAR                *pszSubCategory,
  [in]  const WCHAR                *pszProviderInstanceIdentity,
  [in]  INT_PTR                    iProviderInstanceContext,
  [in]  IPropertyStore             *pIPropertyStore,
  [in]  IFunctionDiscoveryProvider *pIFunctionDiscoveryProvider,
  [out] IFunctionInstance          **ppIFunctionInstance
);