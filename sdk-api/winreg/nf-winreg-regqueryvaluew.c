LSTATUS RegQueryValueW(
  [in]                HKEY    hKey,
  [in, optional]      LPCWSTR lpSubKey,
  [out, optional]     LPWSTR  lpData,
  [in, out, optional] PLONG   lpcbData
);