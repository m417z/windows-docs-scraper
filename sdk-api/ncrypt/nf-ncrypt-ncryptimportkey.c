SECURITY_STATUS NCryptImportKey(
  [in]           NCRYPT_PROV_HANDLE hProvider,
  [in, optional] NCRYPT_KEY_HANDLE  hImportKey,
  [in]           LPCWSTR            pszBlobType,
  [in, optional] NCryptBufferDesc   *pParameterList,
  [out]          NCRYPT_KEY_HANDLE  *phKey,
  [in]           PBYTE              pbData,
  [in]           DWORD              cbData,
  [in]           DWORD              dwFlags
);