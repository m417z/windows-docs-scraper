LSTATUS RegLoadMUIStringA(
  [in]            HKEY    hKey,
  [in, optional]  LPCSTR  pszValue,
  [out, optional] LPSTR   pszOutBuf,
  [in]            DWORD   cbOutBuf,
  [out, optional] LPDWORD pcbData,
  [in]            DWORD   Flags,
  [in, optional]  LPCSTR  pszDirectory
);