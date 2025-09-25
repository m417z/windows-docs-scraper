NTSTATUS LsaLookupNames2(
  [in]  LSA_HANDLE                  PolicyHandle,
  [in]  ULONG                       Flags,
  [in]  ULONG                       Count,
  [in]  PLSA_UNICODE_STRING         Names,
  [out] PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains,
  [out] PLSA_TRANSLATED_SID2        *Sids
);