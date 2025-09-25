LSTATUS RegDeleteKeyTransactedA(
  [in] HKEY   hKey,
  [in] LPCSTR lpSubKey,
  [in] REGSAM samDesired,
       DWORD  Reserved,
  [in] HANDLE hTransaction,
       PVOID  pExtendedParameter
);