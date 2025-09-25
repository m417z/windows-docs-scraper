typedef struct _ISCSI_Supported_LB_Policies {
  ULONGLONG  UniqueSessionId;
  ULONG      LoadBalancePolicy;
  ULONG      iSCSI_PathCount;
  ISCSI_Path iSCSI_Paths[1];
} ISCSI_Supported_LB_Policies, *PISCSI_Supported_LB_Policies;