NTSTATUS LsaLookupSids2(
  [in]  LSA_HANDLE                  PolicyHandle,
  [in]  ULONG                       LookupOptions,
  [in]  ULONG                       Count,
  [in]  PSID                        *Sids,
  [out] PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains,
  [out] PLSA_TRANSLATED_NAME        *Names
);