LSTATUS SHSetValueA(
  [in]           HKEY    hkey,
  [in, optional] LPCSTR  pszSubKey,
  [in, optional] LPCSTR  pszValue,
  [in]           DWORD   dwType,
  [in, optional] LPCVOID pvData,
  [in]           DWORD   cbData
);