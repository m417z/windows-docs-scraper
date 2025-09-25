CREDUIAPI BOOL CredPackAuthenticationBufferA(
  [in]      DWORD dwFlags,
  [in]      LPSTR pszUserName,
  [in]      LPSTR pszPassword,
  [out]     PBYTE pPackedCredentials,
  [in, out] DWORD *pcbPackedCredentials
);