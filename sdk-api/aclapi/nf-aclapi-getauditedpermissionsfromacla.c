DWORD GetAuditedPermissionsFromAclA(
  [in]  PACL         pacl,
  [in]  PTRUSTEE_A   pTrustee,
  [out] PACCESS_MASK pSuccessfulAuditedRights,
  [out] PACCESS_MASK pFailedAuditRights
);