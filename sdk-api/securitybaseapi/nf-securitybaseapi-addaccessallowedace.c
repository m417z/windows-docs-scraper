BOOL AddAccessAllowedAce(
  [in, out] PACL  pAcl,
  [in]      DWORD dwAceRevision,
  [in]      DWORD AccessMask,
  [in]      PSID  pSid
);