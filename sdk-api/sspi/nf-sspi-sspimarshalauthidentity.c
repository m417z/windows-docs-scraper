SECURITY_STATUS SEC_ENTRY SspiMarshalAuthIdentity(
  [in]  PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity,
  [out] unsigned long                   *AuthIdentityLength,
  [out] char                            **AuthIdentityByteArray
);