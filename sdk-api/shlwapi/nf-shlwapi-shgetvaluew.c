LSTATUS SHGetValueW(
  [in]                HKEY    hkey,
  [in, optional]      LPCWSTR pszSubKey,
  [in, optional]      LPCWSTR pszValue,
  [out, optional]     DWORD   *pdwType,
  [out, optional]     void    *pvData,
  [in, out, optional] DWORD   *pcbData
);