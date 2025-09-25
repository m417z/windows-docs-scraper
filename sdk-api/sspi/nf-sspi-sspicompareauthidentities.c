SECURITY_STATUS SEC_ENTRY SspiCompareAuthIdentities(
  [in]  PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity1,
  [in]  PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity2,
  [out] PBOOLEAN                        SameSuppliedUser,
  [out] PBOOLEAN                        SameSuppliedIdentity
);