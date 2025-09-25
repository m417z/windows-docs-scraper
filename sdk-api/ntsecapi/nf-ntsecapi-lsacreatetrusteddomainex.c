NTSTATUS LsaCreateTrustedDomainEx(
  [in]  LSA_HANDLE                       PolicyHandle,
  [in]  PTRUSTED_DOMAIN_INFORMATION_EX   TrustedDomainInformation,
  [in]  PTRUSTED_DOMAIN_AUTH_INFORMATION AuthenticationInformation,
  [in]  ACCESS_MASK                      DesiredAccess,
  [out] PLSA_HANDLE                      TrustedDomainHandle
);