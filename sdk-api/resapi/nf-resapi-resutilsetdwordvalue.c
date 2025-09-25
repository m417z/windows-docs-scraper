DWORD ResUtilSetDwordValue(
  [in]      HKEY    hkeyClusterKey,
  [in]      LPCWSTR pszValueName,
  [in]      DWORD   dwNewValue,
  [in, out] LPDWORD pdwOutValue
);