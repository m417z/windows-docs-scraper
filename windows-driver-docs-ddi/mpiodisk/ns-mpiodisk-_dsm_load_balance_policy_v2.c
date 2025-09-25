typedef struct _DSM_Load_Balance_Policy_V2 {
  ULONG            Version;
  ULONG            LoadBalancePolicy;
  ULONG            DSMPathCount;
  ULONG            Reserved;
  MPIO_DSM_Path_V2 DSM_Paths[1];
} DSM_Load_Balance_Policy_V2, *PDSM_Load_Balance_Policy_V2;