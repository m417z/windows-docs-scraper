LSTATUS RegOpenKeyExW(
  [in]           HKEY    hKey,
  [in, optional] LPCWSTR lpSubKey,
  [in]           DWORD   ulOptions,
  [in]           REGSAM  samDesired,
  [out]          PHKEY   phkResult
);