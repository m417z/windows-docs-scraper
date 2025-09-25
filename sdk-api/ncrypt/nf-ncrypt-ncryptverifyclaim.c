SECURITY_STATUS NCryptVerifyClaim(
  [in]           NCRYPT_KEY_HANDLE hSubjectKey,
  [in, optional] NCRYPT_KEY_HANDLE hAuthorityKey,
  [in]           DWORD             dwClaimType,
  [in, optional] NCryptBufferDesc  *pParameterList,
  [in]           PBYTE             pbClaimBlob,
  [in]           DWORD             cbClaimBlob,
  [out]          NCryptBufferDesc  *pOutput,
  [in]           DWORD             dwFlags
);