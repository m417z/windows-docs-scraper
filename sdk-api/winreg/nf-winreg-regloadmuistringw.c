LSTATUS RegLoadMUIStringW(
  [in]            HKEY    hKey,
  [in, optional]  LPCWSTR pszValue,
  [out, optional] LPWSTR  pszOutBuf,
  [in]            DWORD   cbOutBuf,
  [out, optional] LPDWORD pcbData,
  [in]            DWORD   Flags,
  [in, optional]  LPCWSTR pszDirectory
);