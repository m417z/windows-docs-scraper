NTSTATUS LsaQueryTrustedDomainInfoByName(
  [in]  LSA_HANDLE                PolicyHandle,
  [in]  PLSA_UNICODE_STRING       TrustedDomainName,
  [in]  TRUSTED_INFORMATION_CLASS InformationClass,
  [out] PVOID                     *Buffer
);