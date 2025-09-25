DWORD ClusterRegEnumValue(
  [in]                HKEY    hKey,
  [in]                DWORD   dwIndex,
  [out]               LPWSTR  lpszValueName,
  [in, out]           LPDWORD lpcchValueName,
  [out, optional]     LPDWORD lpdwType,
  [out, optional]     LPBYTE  lpData,
  [in, out, optional] LPDWORD lpcbData
);