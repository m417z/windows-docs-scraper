NTSTATUS LsaQueryDomainInformationPolicy(
  [in]  LSA_HANDLE                      PolicyHandle,
  [in]  POLICY_DOMAIN_INFORMATION_CLASS InformationClass,
  [out] PVOID                           *Buffer
);