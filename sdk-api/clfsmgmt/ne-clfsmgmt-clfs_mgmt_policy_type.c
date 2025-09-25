typedef enum _CLFS_MGMT_POLICY_TYPE {
  ClfsMgmtPolicyMaximumSize = 0x0,
  ClfsMgmtPolicyMinimumSize,
  ClfsMgmtPolicyNewContainerSize,
  ClfsMgmtPolicyGrowthRate,
  ClfsMgmtPolicyLogTail,
  ClfsMgmtPolicyAutoShrink,
  ClfsMgmtPolicyAutoGrow,
  ClfsMgmtPolicyNewContainerPrefix,
  ClfsMgmtPolicyNewContainerSuffix,
  ClfsMgmtPolicyNewContainerExtension,
  ClfsMgmtPolicyInvalid
} CLFS_MGMT_POLICY_TYPE, *PCLFS_MGMT_POLICY_TYPE;