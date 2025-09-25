BOOL CredReadDomainCredentialsW(
  [in]  PCREDENTIAL_TARGET_INFORMATIONW TargetInfo,
  [in]  DWORD                           Flags,
  [out] DWORD                           *Count,
  [out] PCREDENTIALW                    **Credential
);