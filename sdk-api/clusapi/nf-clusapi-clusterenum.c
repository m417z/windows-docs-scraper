DWORD ClusterEnum(
  [in]      HCLUSENUM hEnum,
  [in]      DWORD     dwIndex,
  [out]     LPDWORD   lpdwType,
  [out]     LPWSTR    lpszName,
  [in, out] LPDWORD   lpcchName
);