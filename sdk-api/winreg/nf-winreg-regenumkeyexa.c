LSTATUS RegEnumKeyExA(
  [in]                HKEY      hKey,
  [in]                DWORD     dwIndex,
  [out]               LPSTR     lpName,
  [in, out]           LPDWORD   lpcchName,
                      LPDWORD   lpReserved,
  [in, out]           LPSTR     lpClass,
  [in, out, optional] LPDWORD   lpcchClass,
  [out, optional]     PFILETIME lpftLastWriteTime
);