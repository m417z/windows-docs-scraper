CLFSUSER_API BOOL QueryLogPolicy(
  [in]      HANDLE                hLog,
  [in]      CLFS_MGMT_POLICY_TYPE ePolicyType,
  [out]     PCLFS_MGMT_POLICY     pPolicyBuffer,
  [in, out] PULONG                pcbPolicyBuffer
);