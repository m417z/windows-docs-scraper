DWORD ClusterGroupEnum(
  [in]      HGROUPENUM hGroupEnum,
  [in]      DWORD      dwIndex,
  [out]     LPDWORD    lpdwType,
  [out]     LPWSTR     lpszResourceName,
  [in, out] LPDWORD    lpcchName
);