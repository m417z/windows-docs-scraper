SECURITY_STATUS NCryptEncrypt(
  [in]           NCRYPT_KEY_HANDLE hKey,
  [in]           PBYTE             pbInput,
  [in]           DWORD             cbInput,
  [in, optional] VOID              *pPaddingInfo,
  [out]          PBYTE             pbOutput,
  [in]           DWORD             cbOutput,
  [out]          DWORD             *pcbResult,
  [in]           DWORD             dwFlags
);