LSTATUS RegEnumValueA(
  [in]                HKEY    hKey,
  [in]                DWORD   dwIndex,
  [out]               LPSTR   lpValueName,
  [in, out]           LPDWORD lpcchValueName,
                      LPDWORD lpReserved,
  [out, optional]     LPDWORD lpType,
  [out, optional]     LPBYTE  lpData,
  [in, out, optional] LPDWORD lpcbData
);