typedef struct _DSM_QuerySupportedLBPolicies {
  ULONG                   SupportedLBPoliciesCount;
  ULONG                   Reserved;
  DSM_Load_Balance_Policy Supported_LB_Policies[1];
} DSM_QuerySupportedLBPolicies, *PDSM_QuerySupportedLBPolicies;