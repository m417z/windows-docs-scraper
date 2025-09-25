LSTATUS RegEnumKeyExW(
  [in]                HKEY      hKey,
  [in]                DWORD     dwIndex,
  [out]               LPWSTR    lpName,
  [in, out]           LPDWORD   lpcchName,
                      LPDWORD   lpReserved,
  [in, out]           LPWSTR    lpClass,
  [in, out, optional] LPDWORD   lpcchClass,
  [out, optional]     PFILETIME lpftLastWriteTime
);