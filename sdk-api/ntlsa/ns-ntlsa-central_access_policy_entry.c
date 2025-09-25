typedef struct _CENTRAL_ACCESS_POLICY_ENTRY {
  LSA_UNICODE_STRING   Name;
  LSA_UNICODE_STRING   Description;
  LSA_UNICODE_STRING   ChangeId;
  ULONG                LengthAppliesTo;
  PUCHAR               AppliesTo;
  ULONG                LengthSD;
  PSECURITY_DESCRIPTOR SD;
  ULONG                LengthStagedSD;
  PSECURITY_DESCRIPTOR StagedSD;
  ULONG                Flags;
} CENTRAL_ACCESS_POLICY_ENTRY, *PCENTRAL_ACCESS_POLICY_ENTRY;