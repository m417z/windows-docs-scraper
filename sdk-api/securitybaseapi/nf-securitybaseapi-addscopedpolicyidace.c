BOOL AddScopedPolicyIDAce(
  [in, out] PACL  pAcl,
  [in]      DWORD dwAceRevision,
  [in]      DWORD AceFlags,
  [in]      DWORD AccessMask,
  [in]      PSID  pSid
);