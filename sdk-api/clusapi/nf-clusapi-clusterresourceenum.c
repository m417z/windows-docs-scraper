DWORD ClusterResourceEnum(
  [in]      HRESENUM hResEnum,
  [in]      DWORD    dwIndex,
  [out]     LPDWORD  lpdwType,
  [out]     LPWSTR   lpszName,
  [in, out] LPDWORD  lpcchName
);