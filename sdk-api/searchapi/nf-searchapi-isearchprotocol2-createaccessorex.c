HRESULT CreateAccessorEx(
  [in]  LPCWSTR                 pcwszURL,
  [in]  AUTHENTICATION_INFO     *pAuthenticationInfo,
  [in]  INCREMENTAL_ACCESS_INFO *pIncrementalAccessInfo,
  [in]  ITEM_INFO               *pItemInfo,
  [in]  const BLOB              *pUserData,
  [out] IUrlAccessor            **ppAccessor
);