LSTATUS RegSetKeyValueW(
  [in]           HKEY    hKey,
  [in, optional] LPCWSTR lpSubKey,
  [in, optional] LPCWSTR lpValueName,
  [in]           DWORD   dwType,
  [in, optional] LPCVOID lpData,
  [in]           DWORD   cbData
);