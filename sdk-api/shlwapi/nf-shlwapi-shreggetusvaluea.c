LSTATUS SHRegGetUSValueA(
  [in]                LPCSTR pszSubKey,
  [in, optional]      LPCSTR pszValue,
  [in, out, optional] DWORD  *pdwType,
  [out, optional]     void   *pvData,
  [in, out, optional] DWORD  *pcbData,
  [in]                BOOL   fIgnoreHKCU,
  [in, optional]      void   *pvDefaultData,
  [in]                DWORD  dwDefaultDataSize
);