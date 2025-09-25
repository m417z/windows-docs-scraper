DWORD GetAuditedPermissionsFromAclW(
  [in]  PACL         pacl,
  [in]  PTRUSTEE_W   pTrustee,
  [out] PACCESS_MASK pSuccessfulAuditedRights,
  [out] PACCESS_MASK pFailedAuditRights
);