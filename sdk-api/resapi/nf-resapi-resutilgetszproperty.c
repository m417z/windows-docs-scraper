DWORD ResUtilGetSzProperty(
  [out]          LPWSTR             *ppszOutValue,
  [in]           const PCLUSPROP_SZ pValueStruct,
  [in, optional] LPCWSTR            pszOldValue,
  [in, out]      LPBYTE             *ppPropertyList,
  [in, out]      LPDWORD            pcbPropertyListSize
);