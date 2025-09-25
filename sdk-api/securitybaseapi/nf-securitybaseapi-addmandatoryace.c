BOOL AddMandatoryAce(
  [in, out] PACL  pAcl,
  [in]      DWORD dwAceRevision,
  [in]      DWORD AceFlags,
  [in]      DWORD MandatoryPolicy,
  [in]      PSID  pLabelSid
);