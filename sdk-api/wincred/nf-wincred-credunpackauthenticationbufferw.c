CREDUIAPI BOOL CredUnPackAuthenticationBufferW(
  [in]      DWORD  dwFlags,
  [in]      PVOID  pAuthBuffer,
  [in]      DWORD  cbAuthBuffer,
  [out]     LPWSTR pszUserName,
  [in, out] DWORD  *pcchMaxUserName,
  [out]     LPWSTR pszDomainName,
  [in, out] DWORD  *pcchMaxDomainName,
  [out]     LPWSTR pszPassword,
  [in, out] DWORD  *pcchMaxPassword
);