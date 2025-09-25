BOOL AddConditionalAce(
  [in, out] PACL   pAcl,
  [in]      DWORD  dwAceRevision,
  [in]      DWORD  AceFlags,
  [in]      UCHAR  AceType,
  [in]      DWORD  AccessMask,
  [in]      PSID   pSid,
  [in]      PWCHAR ConditionStr,
  [out]     DWORD  *ReturnLength
);