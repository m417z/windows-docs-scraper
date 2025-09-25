typedef struct _DSM_QuerySupportedLBPolicies_V2 {
  ULONG                      SupportedLBPoliciesCount;
  ULONG                      Reserved;
  DSM_Load_Balance_Policy_V2 Supported_LB_Policies[1];
} DSM_QuerySupportedLBPolicies_V2, *PDSM_QuerySupportedLBPolicies_V2;