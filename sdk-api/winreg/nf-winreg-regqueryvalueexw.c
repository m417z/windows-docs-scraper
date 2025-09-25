LSTATUS RegQueryValueExW(
  [in]                HKEY    hKey,
  [in, optional]      LPCWSTR lpValueName,
                      LPDWORD lpReserved,
  [out, optional]     LPDWORD lpType,
  [out, optional]     LPBYTE  lpData,
  [in, out, optional] LPDWORD lpcbData
);