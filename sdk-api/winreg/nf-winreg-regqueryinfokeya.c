LSTATUS RegQueryInfoKeyA(
  [in]                HKEY      hKey,
  [out, optional]     LPSTR     lpClass,
  [in, out, optional] LPDWORD   lpcchClass,
                      LPDWORD   lpReserved,
  [out, optional]     LPDWORD   lpcSubKeys,
  [out, optional]     LPDWORD   lpcbMaxSubKeyLen,
  [out, optional]     LPDWORD   lpcbMaxClassLen,
  [out, optional]     LPDWORD   lpcValues,
  [out, optional]     LPDWORD   lpcbMaxValueNameLen,
  [out, optional]     LPDWORD   lpcbMaxValueLen,
  [out, optional]     LPDWORD   lpcbSecurityDescriptor,
  [out, optional]     PFILETIME lpftLastWriteTime
);