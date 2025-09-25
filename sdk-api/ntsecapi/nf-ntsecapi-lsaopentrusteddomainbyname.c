NTSTATUS LsaOpenTrustedDomainByName(
  [in]  LSA_HANDLE          PolicyHandle,
  [in]  PLSA_UNICODE_STRING TrustedDomainName,
  [in]  ACCESS_MASK         DesiredAccess,
  [out] PLSA_HANDLE         TrustedDomainHandle
);