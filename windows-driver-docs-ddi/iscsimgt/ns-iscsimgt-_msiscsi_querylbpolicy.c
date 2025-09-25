typedef struct _MSiSCSI_QueryLBPolicy {
  ULONGLONG                   UniqueAdapterId;
  ULONG                       Reserved;
  ULONG                       SessionCount;
  ISCSI_Supported_LB_Policies LoadBalancePolicies[1];
} MSiSCSI_QueryLBPolicy, *PMSiSCSI_QueryLBPolicy;