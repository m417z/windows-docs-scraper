LSTATUS RegOpenKeyTransactedA(
  [in]           HKEY   hKey,
  [in, optional] LPCSTR lpSubKey,
  [in]           DWORD  ulOptions,
  [in]           REGSAM samDesired,
  [out]          PHKEY  phkResult,
  [in]           HANDLE hTransaction,
                 PVOID  pExtendedParemeter
);