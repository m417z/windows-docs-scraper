LSTATUS RegSetKeyValueA(
  [in]           HKEY    hKey,
  [in, optional] LPCSTR  lpSubKey,
  [in, optional] LPCSTR  lpValueName,
  [in]           DWORD   dwType,
  [in, optional] LPCVOID lpData,
  [in]           DWORD   cbData
);