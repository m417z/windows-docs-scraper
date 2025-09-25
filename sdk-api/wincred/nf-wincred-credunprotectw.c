BOOL CredUnprotectW(
  [in]      BOOL   fAsSelf,
  [in]      LPWSTR pszProtectedCredentials,
  [in]      DWORD  cchProtectedCredentials,
  [out]     LPWSTR pszCredentials,
  [in, out] DWORD  *pcchMaxChars
);