typedef struct _CENTRAL_ACCESS_POLICY {
  PSID                         CAPID;
  LSA_UNICODE_STRING           Name;
  LSA_UNICODE_STRING           Description;
  LSA_UNICODE_STRING           ChangeId;
  ULONG                        Flags;
  ULONG                        CAPECount;
  PCENTRAL_ACCESS_POLICY_ENTRY *CAPEs;
} CENTRAL_ACCESS_POLICY, *PCENTRAL_ACCESS_POLICY;