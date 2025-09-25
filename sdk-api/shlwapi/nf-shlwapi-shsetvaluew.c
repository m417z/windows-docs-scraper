LSTATUS SHSetValueW(
  [in]           HKEY    hkey,
  [in, optional] LPCWSTR pszSubKey,
  [in, optional] LPCWSTR pszValue,
  [in]           DWORD   dwType,
  [in, optional] LPCVOID pvData,
  [in]           DWORD   cbData
);