LSTATUS RegDeleteKeyTransactedW(
  [in] HKEY    hKey,
  [in] LPCWSTR lpSubKey,
  [in] REGSAM  samDesired,
       DWORD   Reserved,
  [in] HANDLE  hTransaction,
       PVOID   pExtendedParameter
);