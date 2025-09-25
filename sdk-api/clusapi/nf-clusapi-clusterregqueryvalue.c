LONG ClusterRegQueryValue(
  [in]                HKEY    hKey,
  [in]                LPCWSTR lpszValueName,
  [out, optional]     LPDWORD lpdwValueType,
  [out, optional]     LPBYTE  lpData,
  [in, out, optional] LPDWORD lpcbData
);