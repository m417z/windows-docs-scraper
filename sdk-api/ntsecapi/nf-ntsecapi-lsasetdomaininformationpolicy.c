NTSTATUS LsaSetDomainInformationPolicy(
  [in] LSA_HANDLE                      PolicyHandle,
  [in] POLICY_DOMAIN_INFORMATION_CLASS InformationClass,
  [in] PVOID                           Buffer
);