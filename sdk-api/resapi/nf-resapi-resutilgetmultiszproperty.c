DWORD ResUtilGetMultiSzProperty(
  [out]          LPWSTR             *ppszOutValue,
  [out]          LPDWORD            pcbOutValueSize,
  [in]           const PCLUSPROP_SZ pValueStruct,
  [in, optional] LPCWSTR            pszOldValue,
  [in]           DWORD              cbOldValueSize,
  [in, out]      LPBYTE             *ppPropertyList,
  [in, out]      LPDWORD            pcbPropertyListSize
);