BOOL AddAccessDeniedAce(
  [in, out] PACL  pAcl,
  [in]      DWORD dwAceRevision,
  [in]      DWORD AccessMask,
  [in]      PSID  pSid
);