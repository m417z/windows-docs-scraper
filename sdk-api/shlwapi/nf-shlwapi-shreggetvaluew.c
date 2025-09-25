LSTATUS SHRegGetValueW(
  [in]      HKEY    hkey,
  [in]      LPCWSTR pszSubKey,
  [in]      LPCWSTR pszValue,
  [in]      SRRF    srrfFlags,
  [in, out] DWORD   *pdwType,
  [out]     void    *pvData,
  [in, out] DWORD   *pcbData
);