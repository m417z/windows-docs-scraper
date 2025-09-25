LONG ClusterRegQueryInfoKey(
  [in] HKEY      hKey,
  [in] LPDWORD   lpcSubKeys,
  [in] LPDWORD   lpcchMaxSubKeyLen,
  [in] LPDWORD   lpcValues,
  [in] LPDWORD   lpcchMaxValueNameLen,
  [in] LPDWORD   lpcbMaxValueLen,
  [in] LPDWORD   lpcbSecurityDescriptor,
  [in] PFILETIME lpftLastWriteTime
);