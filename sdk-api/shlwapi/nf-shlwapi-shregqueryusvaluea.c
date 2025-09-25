LSTATUS SHRegQueryUSValueA(
  [in]                HUSKEY hUSKey,
  [in, optional]      LPCSTR pszValue,
  [in, out, optional] DWORD  *pdwType,
  [out, optional]     void   *pvData,
  [in, out]           DWORD  *pcbData,
  [in]                BOOL   fIgnoreHKCU,
  [in, optional]      void   *pvDefaultData,
  [in, optional]      DWORD  dwDefaultDataSize
);