NTSTATUS LsaSetTrustedDomainInformation(
  [in] LSA_HANDLE                PolicyHandle,
  [in] PSID                      TrustedDomainSid,
  [in] TRUSTED_INFORMATION_CLASS InformationClass,
  [in] PVOID                     Buffer
);