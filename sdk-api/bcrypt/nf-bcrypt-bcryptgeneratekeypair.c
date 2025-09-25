NTSTATUS BCryptGenerateKeyPair(
  [in, out] BCRYPT_ALG_HANDLE hAlgorithm,
  [out]     BCRYPT_KEY_HANDLE *phKey,
  [in]      ULONG             dwLength,
  [in]      ULONG             dwFlags
);