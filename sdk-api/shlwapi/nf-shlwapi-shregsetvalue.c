LSTATUS SHRegSetValue(
  [in] HKEY    hkey,
  [in] LPCWSTR pszSubKey,
  [in] LPCWSTR pszValue,
  [in] SRRF    srrfFlags,
  [in] DWORD   dwType,
  [in] LPCVOID pvData,
  [in] DWORD   cbData
);