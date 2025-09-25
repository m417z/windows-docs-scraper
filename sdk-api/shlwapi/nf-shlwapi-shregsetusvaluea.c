LSTATUS SHRegSetUSValueA(
  [in]           LPCSTR     pszSubKey,
  [in]           LPCSTR     pszValue,
  [in]           DWORD      dwType,
  [in, optional] const void *pvData,
  [in, optional] DWORD      cbData,
  [in, optional] DWORD      dwFlags
);