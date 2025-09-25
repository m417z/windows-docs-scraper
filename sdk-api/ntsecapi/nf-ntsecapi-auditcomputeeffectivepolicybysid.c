BOOLEAN AuditComputeEffectivePolicyBySid(
  [in]  const PSID                pSid,
  [in]  const GUID                *pSubCategoryGuids,
  [in]  ULONG                     dwPolicyCount,
  [out] PAUDIT_POLICY_INFORMATION *ppAuditPolicy
);