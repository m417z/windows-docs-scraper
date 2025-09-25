DWORD ClusterNetworkEnum(
  [in]      HNETWORKENUM hNetworkEnum,
  [in]      DWORD        dwIndex,
  [out]     LPDWORD      lpdwType,
  [out]     LPWSTR       lpszName,
  [in, out] LPDWORD      lpcchName
);