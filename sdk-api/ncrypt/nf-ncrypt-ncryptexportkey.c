SECURITY_STATUS NCryptExportKey(
  [in]            NCRYPT_KEY_HANDLE hKey,
  [in, optional]  NCRYPT_KEY_HANDLE hExportKey,
  [in]            LPCWSTR           pszBlobType,
  [in, optional]  NCryptBufferDesc  *pParameterList,
  [out, optional] PBYTE             pbOutput,
  [in]            DWORD             cbOutput,
  [out]           DWORD             *pcbResult,
  [in]            DWORD             dwFlags
);