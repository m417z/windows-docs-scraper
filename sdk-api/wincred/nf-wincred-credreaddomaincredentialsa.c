BOOL CredReadDomainCredentialsA(
  [in]  PCREDENTIAL_TARGET_INFORMATIONA TargetInfo,
  [in]  DWORD                           Flags,
  [out] DWORD                           *Count,
  [out] PCREDENTIALA                    **Credential
);