NTSTATUS LsaEnumerateTrustedDomains(
  [in]  LSA_HANDLE              PolicyHandle,
  [in]  PLSA_ENUMERATION_HANDLE EnumerationContext,
  [out] PVOID                   *Buffer,
  [in]  ULONG                   PreferedMaximumLength,
  [out] PULONG                  CountReturned
);