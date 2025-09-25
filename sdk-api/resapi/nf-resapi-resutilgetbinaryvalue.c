DWORD ResUtilGetBinaryValue(
  [in]            HKEY    hkeyClusterKey,
  [in]            LPCWSTR pszValueName,
  [out, optional] LPBYTE  *ppbOutValue,
  [out]           LPDWORD pcbOutValueSize
);