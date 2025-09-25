SECURITY_STATUS SEC_ENTRY SspiPrepareForCredRead(
  [in]  PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity,
  [in]  PCWSTR                          pszTargetName,
  [out] PULONG                          pCredmanCredentialType,
  [out] PCWSTR                          *ppszCredmanTargetName
);