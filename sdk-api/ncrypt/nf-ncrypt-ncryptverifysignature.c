SECURITY_STATUS NCryptVerifySignature(
  [in]           NCRYPT_KEY_HANDLE hKey,
  [in, optional] VOID              *pPaddingInfo,
  [in]           PBYTE             pbHashValue,
  [in]           DWORD             cbHashValue,
  [in]           PBYTE             pbSignature,
  [in]           DWORD             cbSignature,
  [in]           DWORD             dwFlags
);