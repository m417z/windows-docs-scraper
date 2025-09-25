SECURITY_STATUS NCryptKeyDerivation(
  [in]  NCRYPT_KEY_HANDLE hKey,
  [in]  NCryptBufferDesc  *pParameterList,
  [out] PUCHAR            pbDerivedKey,
  [in]  DWORD             cbDerivedKey,
  [out] DWORD             *pcbResult,
  [in]  ULONG             dwFlags
);