KSECDDDECLSPEC NTSTATUS SEC_ENTRY SecLookupAccountName(
  [in]               PUNICODE_STRING Name,
  [in, out]          PULONG          SidSize,
  [out]              PSID            Sid,
  [out]              PSID_NAME_USE   NameUse,
  [out]              PULONG          DomainSize,
  [in_out, optional] PUNICODE_STRING ReferencedDomain
);