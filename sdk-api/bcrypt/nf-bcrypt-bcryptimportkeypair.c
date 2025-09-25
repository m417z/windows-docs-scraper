NTSTATUS BCryptImportKeyPair(
  [in]      BCRYPT_ALG_HANDLE hAlgorithm,
  [in, out] BCRYPT_KEY_HANDLE hImportKey,
  [in]      LPCWSTR           pszBlobType,
  [out]     BCRYPT_KEY_HANDLE *phKey,
  [in]      PUCHAR            pbInput,
  [in]      ULONG             cbInput,
  [in]      ULONG             dwFlags
);