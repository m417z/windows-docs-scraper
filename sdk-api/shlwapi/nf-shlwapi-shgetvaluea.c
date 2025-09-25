LSTATUS SHGetValueA(
  [in]                HKEY   hkey,
  [in, optional]      LPCSTR pszSubKey,
  [in, optional]      LPCSTR pszValue,
  [out, optional]     DWORD  *pdwType,
  [out, optional]     void   *pvData,
  [in, out, optional] DWORD  *pcbData
);