NTSTATUS LsaQueryTrustedDomainInfo(
  [in]  LSA_HANDLE                PolicyHandle,
  [in]  PSID                      TrustedDomainSid,
  [in]  TRUSTED_INFORMATION_CLASS InformationClass,
  [out] PVOID                     *Buffer
);