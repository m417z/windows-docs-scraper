DWORD ResUtilEnumPrivateProperties(
  [in]  HKEY    hkeyClusterKey,
  [out] LPWSTR  pszOutProperties,
  [in]  DWORD   cbOutPropertiesSize,
  [out] LPDWORD pcbBytesReturned,
  [out] LPDWORD pcbRequired
);