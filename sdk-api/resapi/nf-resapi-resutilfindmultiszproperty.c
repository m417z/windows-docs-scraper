DWORD ResUtilFindMultiSzProperty(
  [in]  const PVOID pPropertyList,
  [in]  DWORD       cbPropertyListSize,
  [in]  LPCWSTR     pszPropertyName,
  [out] LPWSTR      *pszPropertyValue,
  [out] LPDWORD     pcbPropertyValueSize
);