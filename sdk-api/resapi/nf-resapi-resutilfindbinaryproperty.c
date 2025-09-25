DWORD ResUtilFindBinaryProperty(
  [in]            const PVOID pPropertyList,
  [in]            DWORD       cbPropertyListSize,
  [in]            LPCWSTR     pszPropertyName,
  [out, optional] LPBYTE      *pbPropertyValue,
  [out, optional] LPDWORD     pcbPropertyValueSize
);