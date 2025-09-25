BOOLEAN AuditComputeEffectivePolicyByToken(
  [in]  HANDLE                    hTokenHandle,
  [in]  const GUID                *pSubCategoryGuids,
  [in]  ULONG                     dwPolicyCount,
  [out] PAUDIT_POLICY_INFORMATION *ppAuditPolicy
);