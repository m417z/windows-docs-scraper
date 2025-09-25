DWORD ResUtilSetMultiSzValue(
  [in]                HKEY    hkeyClusterKey,
  [in]                LPCWSTR pszValueName,
  [in]                LPCWSTR pszNewValue,
  [in]                DWORD   cbNewValueSize,
  [out, optional]     LPWSTR  *ppszOutValue,
  [in, out, optional] LPDWORD pcbOutValueSize
);