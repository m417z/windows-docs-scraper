LSTATUS RegSaveKeyExW(
  [in]           HKEY                        hKey,
  [in]           LPCWSTR                     lpFile,
  [in, optional] const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [in]           DWORD                       Flags
);