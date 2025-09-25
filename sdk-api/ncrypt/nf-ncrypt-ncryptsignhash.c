SECURITY_STATUS NCryptSignHash(
  [in]           NCRYPT_KEY_HANDLE hKey,
  [in, optional] VOID              *pPaddingInfo,
  [in]           PBYTE             pbHashValue,
  [in]           DWORD             cbHashValue,
  [out]          PBYTE             pbSignature,
  [in]           DWORD             cbSignature,
  [out]          DWORD             *pcbResult,
  [in]           DWORD             dwFlags
);