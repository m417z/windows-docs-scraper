SECURITY_STATUS SEC_ENTRY SspiEncodeAuthIdentityAsStrings(
  [in]  PSEC_WINNT_AUTH_IDENTITY_OPAQUE pAuthIdentity,
  [out] PCWSTR                          *ppszUserName,
  [out] PCWSTR                          *ppszDomainName,
  [out] PCWSTR                          *ppszPackedCredentialsString
);