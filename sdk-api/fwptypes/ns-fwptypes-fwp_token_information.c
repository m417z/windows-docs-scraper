typedef struct FWP_TOKEN_INFORMATION_ {
  ULONG               sidCount;
  PSID_AND_ATTRIBUTES sids;
  ULONG               restrictedSidCount;
  PSID_AND_ATTRIBUTES restrictedSids;
} FWP_TOKEN_INFORMATION;