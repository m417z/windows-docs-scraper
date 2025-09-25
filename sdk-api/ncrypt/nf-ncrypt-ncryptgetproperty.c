SECURITY_STATUS NCryptGetProperty(
  [in]  NCRYPT_HANDLE hObject,
  [in]  LPCWSTR       pszProperty,
  [out] PBYTE         pbOutput,
  [in]  DWORD         cbOutput,
  [out] DWORD         *pcbResult,
  [in]  DWORD         dwFlags
);