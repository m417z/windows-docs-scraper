NTSTATUS BCryptKeyDerivation(
  [in]           BCRYPT_KEY_HANDLE hKey,
  [in, optional] BCryptBufferDesc  *pParameterList,
  [out]          PUCHAR            pbDerivedKey,
  [in]           ULONG             cbDerivedKey,
  [out]          ULONG             *pcbResult,
  [in]           ULONG             dwFlags
);