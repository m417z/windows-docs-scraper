BOOL CredProtectA(
  [in]      BOOL                 fAsSelf,
  [in]      LPSTR                pszCredentials,
  [in]      DWORD                cchCredentials,
  [out]     LPSTR                pszProtectedCredentials,
  [in, out] DWORD                *pcchMaxChars,
  [out]     CRED_PROTECTION_TYPE *ProtectionType
);