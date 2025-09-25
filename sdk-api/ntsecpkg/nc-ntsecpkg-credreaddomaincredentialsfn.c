CredReadDomainCredentialsFn Credreaddomaincredentialsfn;

NTSTATUS Credreaddomaincredentialsfn(
  [in]  PLUID LogonId,
  [in]  ULONG CredFlags,
  [in]  PCREDENTIAL_TARGET_INFORMATIONW TargetInfo,
        ULONG Flags,
        PULONG Count,
  [out] PENCRYPTED_CREDENTIALW **Credential
)
{...}