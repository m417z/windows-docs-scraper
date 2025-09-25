SECURITY_STATUS SEC_ENTRY SspiExcludePackage(
  [in]  PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity,
  [in]  PCWSTR                          pszPackageName,
  [out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE *ppNewAuthIdentity
);