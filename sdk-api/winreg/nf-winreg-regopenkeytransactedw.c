LSTATUS RegOpenKeyTransactedW(
  [in]           HKEY    hKey,
  [in, optional] LPCWSTR lpSubKey,
  [in]           DWORD   ulOptions,
  [in]           REGSAM  samDesired,
  [out]          PHKEY   phkResult,
  [in]           HANDLE  hTransaction,
                 PVOID   pExtendedParemeter
);