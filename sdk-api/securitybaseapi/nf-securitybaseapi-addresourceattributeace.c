BOOL AddResourceAttributeAce(
  [in, out] PACL                                   pAcl,
  [in]      DWORD                                  dwAceRevision,
  [in]      DWORD                                  AceFlags,
  [in]      DWORD                                  AccessMask,
  [in]      PSID                                   pSid,
  [in]      PCLAIM_SECURITY_ATTRIBUTES_INFORMATION pAttributeInfo,
  [out]     PDWORD                                 pReturnLength
);