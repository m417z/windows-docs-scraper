KSECDDDECLSPEC NTSTATUS SEC_ENTRY SecLookupAccountSid(
  [in]            PSID            Sid,
  [out]           PULONG          NameSize,
  [in, out]       PUNICODE_STRING NameBuffer,
  [out]           PULONG          DomainSize,
  [out, optional] PUNICODE_STRING DomainBuffer,
  [out]           PSID_NAME_USE   NameUse
);