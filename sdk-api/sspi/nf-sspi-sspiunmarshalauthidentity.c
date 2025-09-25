SECURITY_STATUS SEC_ENTRY SspiUnmarshalAuthIdentity(
  [in]  unsigned long                   AuthIdentityLength,
  [in]  char                            *AuthIdentityByteArray,
  [out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE *ppAuthIdentity
);