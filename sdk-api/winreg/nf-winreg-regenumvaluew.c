LSTATUS RegEnumValueW(
  [in]                HKEY    hKey,
  [in]                DWORD   dwIndex,
  [out]               LPWSTR  lpValueName,
  [in, out]           LPDWORD lpcchValueName,
                      LPDWORD lpReserved,
  [out, optional]     LPDWORD lpType,
  [out, optional]     LPBYTE  lpData,
  [in, out, optional] LPDWORD lpcbData
);