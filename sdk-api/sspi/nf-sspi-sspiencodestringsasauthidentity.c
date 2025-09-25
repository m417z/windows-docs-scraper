SECURITY_STATUS SEC_ENTRY SspiEncodeStringsAsAuthIdentity(
  [in]  PCWSTR                          pszUserName,
  [in]  PCWSTR                          pszDomainName,
  [in]  PCWSTR                          pszPackedCredentialsString,
  [out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE *ppAuthIdentity
);