SECURITY_STATUS SEC_ENTRY SspiPrepareForCredWrite(
  [in]  PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity,
  [in]  PCWSTR                          pszTargetName,
  [out] PULONG                          pCredmanCredentialType,
  [out] PCWSTR                          *ppszCredmanTargetName,
  [out] PCWSTR                          *ppszCredmanUserName,
  [out] PUCHAR                          *ppCredentialBlob,
  [out] PULONG                          pCredentialBlobSize
);