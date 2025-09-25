HRESULT CreateAccessor(
  [in]  LPCWSTR                 pcwszURL,
  [in]  AUTHENTICATION_INFO     *pAuthenticationInfo,
  [in]  INCREMENTAL_ACCESS_INFO *pIncrementalAccessInfo,
  [in]  ITEM_INFO               *pItemInfo,
  [out] IUrlAccessor            **ppAccessor
);