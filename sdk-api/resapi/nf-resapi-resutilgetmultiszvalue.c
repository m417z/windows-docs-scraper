DWORD WINAPI_INLINE ResUtilGetMultiSzValue(
  [in]            HKEY    hkeyClusterKey,
  [in]            LPCWSTR pszValueName,
  [out, optional] LPWSTR  *ppszOutValue,
  [out]           LPDWORD pcbOutValueSize
);