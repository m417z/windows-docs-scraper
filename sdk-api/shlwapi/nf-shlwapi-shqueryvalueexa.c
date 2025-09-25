LSTATUS SHQueryValueExA(
  [in]                HKEY   hkey,
  [in, optional]      LPCSTR pszValue,
                      DWORD  *pdwReserved,
  [out, optional]     DWORD  *pdwType,
  [out, optional]     void   *pvData,
  [in, out, optional] DWORD  *pcbData
);