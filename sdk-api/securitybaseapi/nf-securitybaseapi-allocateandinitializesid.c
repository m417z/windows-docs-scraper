BOOL AllocateAndInitializeSid(
  [in]  PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
  [in]  BYTE                      nSubAuthorityCount,
  [in]  DWORD                     nSubAuthority0,
  [in]  DWORD                     nSubAuthority1,
  [in]  DWORD                     nSubAuthority2,
  [in]  DWORD                     nSubAuthority3,
  [in]  DWORD                     nSubAuthority4,
  [in]  DWORD                     nSubAuthority5,
  [in]  DWORD                     nSubAuthority6,
  [in]  DWORD                     nSubAuthority7,
  [out] PSID                      *pSid
);