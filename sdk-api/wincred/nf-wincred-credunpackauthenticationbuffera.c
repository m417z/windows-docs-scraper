CREDUIAPI BOOL CredUnPackAuthenticationBufferA(
  [in]      DWORD dwFlags,
  [in]      PVOID pAuthBuffer,
  [in]      DWORD cbAuthBuffer,
  [out]     LPSTR pszUserName,
  [in, out] DWORD *pcchlMaxUserName,
  [out]     LPSTR pszDomainName,
  [in, out] DWORD *pcchMaxDomainName,
  [out]     LPSTR pszPassword,
  [in, out] DWORD *pcchMaxPassword
);