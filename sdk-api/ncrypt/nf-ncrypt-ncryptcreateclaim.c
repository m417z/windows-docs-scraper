SECURITY_STATUS NCryptCreateClaim(
  [in]           NCRYPT_KEY_HANDLE hSubjectKey,
  [in, optional] NCRYPT_KEY_HANDLE hAuthorityKey,
  [in]           DWORD             dwClaimType,
  [in, optional] NCryptBufferDesc  *pParameterList,
  [out]          PBYTE             pbClaimBlob,
  [in]           DWORD             cbClaimBlob,
  [out]          DWORD             *pcbResult,
  [in]           DWORD             dwFlags
);