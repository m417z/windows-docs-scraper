CREDUIAPI BOOL CredPackAuthenticationBufferW(
  [in]      DWORD  dwFlags,
  [in]      LPWSTR pszUserName,
  [in]      LPWSTR pszPassword,
  [out]     PBYTE  pPackedCredentials,
  [in, out] DWORD  *pcbPackedCredentials
);