LSTATUS SHRegGetUSValueW(
  [in]                LPCWSTR pszSubKey,
  [in, optional]      LPCWSTR pszValue,
  [in, out, optional] DWORD   *pdwType,
  [out, optional]     void    *pvData,
  [in, out, optional] DWORD   *pcbData,
  [in]                BOOL    fIgnoreHKCU,
  [in, optional]      void    *pvDefaultData,
  [in]                DWORD   dwDefaultDataSize
);