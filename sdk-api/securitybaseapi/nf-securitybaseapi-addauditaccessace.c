BOOL AddAuditAccessAce(
  [in, out] PACL  pAcl,
  [in]      DWORD dwAceRevision,
  [in]      DWORD dwAccessMask,
  [in]      PSID  pSid,
  [in]      BOOL  bAuditSuccess,
  [in]      BOOL  bAuditFailure
);