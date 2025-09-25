typedef struct _DSM_Load_Balance_Policy {
  ULONG         Version;
  ULONG         LoadBalancePolicy;
  ULONG         DSMPathCount;
  ULONG         Reserved;
  MPIO_DSM_Path DSM_Paths[1];
} DSM_Load_Balance_Policy, *PDSM_Load_Balance_Policy;