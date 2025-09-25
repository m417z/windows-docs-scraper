LONG ClusterRegEnumKey(
  [in]            HKEY      hKey,
  [in]            DWORD     dwIndex,
  [out]           LPWSTR    lpszName,
  [in, out]       LPDWORD   lpcchName,
  [out, optional] PFILETIME lpftLastWriteTime
);