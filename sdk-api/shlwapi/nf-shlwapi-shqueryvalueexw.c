LSTATUS SHQueryValueExW(
  [in]                HKEY    hkey,
  [in, optional]      LPCWSTR pszValue,
                      DWORD   *pdwReserved,
  [out, optional]     DWORD   *pdwType,
  [out, optional]     void    *pvData,
  [in, out, optional] DWORD   *pcbData
);