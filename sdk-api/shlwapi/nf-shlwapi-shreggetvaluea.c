LSTATUS SHRegGetValueA(
  [in]      HKEY   hkey,
  [in]      LPCSTR pszSubKey,
  [in]      LPCSTR pszValue,
  [in]      SRRF   srrfFlags,
  [in, out] DWORD  *pdwType,
  [out]     void   *pvData,
  [in, out] DWORD  *pcbData
);