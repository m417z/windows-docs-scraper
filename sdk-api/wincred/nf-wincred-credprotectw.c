BOOL CredProtectW(
  [in]      BOOL                 fAsSelf,
  [in]      LPWSTR               pszCredentials,
  [in]      DWORD                cchCredentials,
  [out]     LPWSTR               pszProtectedCredentials,
  [in, out] DWORD                *pcchMaxChars,
  [out]     CRED_PROTECTION_TYPE *ProtectionType
);