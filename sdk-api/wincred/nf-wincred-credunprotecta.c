BOOL CredUnprotectA(
  [in]      BOOL  fAsSelf,
  [in]      LPSTR pszProtectedCredentials,
  [in]      DWORD cchProtectedCredentials,
  [out]     LPSTR pszCredentials,
  [in, out] DWORD *pcchMaxChars
);