HRESULT Initialize(
  [in]  IFunctionDiscoveryProviderFactory *pIFunctionDiscoveryProviderFactory,
  [in]  IFunctionDiscoveryNotification    *pIFunctionDiscoveryNotification,
  [in]  LCID                              lcidUserDefault,
  [out] DWORD                             *pdwStgAccessCapabilities
);